import traceback

from File import File
from Directory import Directory
from FileTreatmentException import FileTreatmentException

def main():
    try:
        rootdir = Directory("root")

        usrdir = Directory("usr")
        rootdir.add(usrdir)

        yuki = Directory("yuki")
        usrdir.add(yuki)

        file_ = File("Composite.java", 100)
        yuki.add(file_)
        rootdir.printList()

        print("")
        print("file = " + file_.getFullName())
        print("yuki = " + yuki.getFullName())
    except FileTreatmentException as e:
        traceback.print_exc()

if __name__ == "__main__":
    main()
