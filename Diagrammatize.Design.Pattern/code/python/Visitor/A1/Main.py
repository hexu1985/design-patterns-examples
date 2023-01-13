import traceback

from File import File
from Directory import Directory
from FileFindVisitor import FileFindVisitor
from FileTreatmentException import FileTreatmentException

def main():
    try:
        rootdir = Directory("root")
        bindir = Directory("bin")
        tmpdir = Directory("tmp")
        usrdir = Directory("usr")
        rootdir.add(bindir)
        rootdir.add(tmpdir)
        rootdir.add(usrdir)
        bindir.add(File("vi", 10000))
        bindir.add(File("latex", 20000))

        yuki = Directory("yuki")
        hanako = Directory("hanako")
        tomura = Directory("tomura")
        usrdir.add(yuki)
        usrdir.add(hanako)
        usrdir.add(tomura)
        yuki.add(File("diary.html", 100))
        yuki.add(File("Composite.java", 200))
        hanako.add(File("memo.tex", 300))
        hanako.add(File("index.html", 350))
        tomura.add(File("game.doc", 400))
        tomura.add(File("junk.mail", 500))

        ffv = FileFindVisitor(".html")
        rootdir.accept(ffv)              

        print("HTML files are:")
        for file_ in ffv.getFoundFiles():
            print(str(file_))

    except FileTreatmentException as e:
        traceback.print_exec()


if __name__ == "__main__":
    main()
