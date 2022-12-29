#include <iostream>
#include "Directory.hpp"
#include "File.hpp"
#include "ListVisitor.hpp"
#include "FileFindVisitor.hpp"

using namespace std;

int main() {
    Directory* rootdir = new Directory("root");
    Directory* bindir = new Directory("bin");
    Directory* tmpdir = new Directory("tmp");
    Directory* usrdir = new Directory("usr");
    rootdir->add(bindir);
    rootdir->add(tmpdir);
    rootdir->add(usrdir);
    bindir->add(new File("vi", 10000));
    bindir->add(new File("latex", 20000));

    Directory* yuki = new Directory("yuki");
    Directory* hanako = new Directory("hanako");
    Directory* tomura = new Directory("tomura");
    usrdir->add(yuki);
    usrdir->add(hanako);
    usrdir->add(tomura);
    yuki->add(new File("diary.html", 100));
    yuki->add(new File("Composite.java", 200));
    hanako->add(new File("memo.tex", 300));
    hanako->add(new File("index.html", 350));
    tomura->add(new File("game.doc", 400));
    tomura->add(new File("junk.mail", 500));

    FileFindVisitor *ffv = new FileFindVisitor(".html");     
    rootdir->accept(ffv);                                    

    std::cout << "HTML files are:" << '\n';
    for (auto file : ffv->getFoundFiles()) {
        std::cout << file->toString() << '\n';
    }
}
