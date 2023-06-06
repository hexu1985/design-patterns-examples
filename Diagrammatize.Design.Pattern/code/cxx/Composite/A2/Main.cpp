#include "FileTreatmentException.hpp"
#include "File.hpp"
#include "Directory.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    try {
        Directory* rootdir = new Directory("root");

        Directory* usrdir = new Directory("usr");
        rootdir->add(usrdir);

        Directory* yuki = new Directory("yuki");
        usrdir->add(yuki);

        File* file = new File("Composite.java", 100);
        yuki->add(file);
        rootdir->printList();

        std::cout << std::endl;
        std::cout << "file = " << file->getFullName() << std::endl;
        std::cout << "yuki = " << yuki->getFullName() << std::endl;
    } catch (const FileTreatmentException& e) {
        std::cout << e.what() << std::endl;
    }
}
