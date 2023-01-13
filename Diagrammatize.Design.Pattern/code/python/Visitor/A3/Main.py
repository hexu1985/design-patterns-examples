import traceback

from File import File
from Directory import Directory
from ElementArrayList import ElementArrayList
from ListVisitor import ListVisitor
from FileTreatmentException import FileTreatmentException

def main():
    try:
        root1 = Directory("root1")
        root1.add(File("diary.html", 10))
        root1.add(File("index.html", 20))
        
        root2 = Directory("root2")
        root2.add(File("diary.html", 1000))
        root2.add(File("index.html", 2000))
        
        list_ = ElementArrayList()
        list_.append(root1)
        list_.append(root2)
        list_.append(File("etc.html", 1234))
        
        list_.accept(ListVisitor())
    except FileTreatmentException as e:
        traceback.print_exec()


if __name__ == "__main__":
    main()
