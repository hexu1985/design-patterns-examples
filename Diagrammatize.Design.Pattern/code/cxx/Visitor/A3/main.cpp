#include <iostream>
#include "Directory.hpp"
#include "File.hpp"
#include "ListVisitor.hpp"
#include "ElementArrayList.hpp"

using namespace std;

int main() {
    Directory* root1 = new Directory("root1");
    root1->add(new File("diary.html", 10));
    root1->add(new File("index.html", 20));

    Directory* root2 = new Directory("root2");
    root2->add(new File("diary.html", 1000));
    root2->add(new File("index.html", 2000));

    ElementArrayList* list = new ElementArrayList();
    list->push_back(root1);
    list->push_back(root2);
    list->push_back(new File("etc.html", 1234));

    list->accept(new ListVisitor());
}
