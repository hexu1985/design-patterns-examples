#include "Page.hpp"
#include <fstream>
#include <iostream>

Page::Page(const std::string& title_, const std::string& author_): title(title_), author(author_) {
}

void Page::add(Item* item) {
    content.push_back(item);
}

void Page::output() {
    std::string filename = title + ".html";
    std::ofstream writer;
    writer.open(filename);
    writer << makeHTML();
    writer.close();
    std::cout << filename << " 编写完成。" << std::endl;
}
