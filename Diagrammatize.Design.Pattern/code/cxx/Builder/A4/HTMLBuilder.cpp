#include "HTMLBuilder.hpp"
#include <iostream>

HTMLBuilder::~HTMLBuilder() {
}

void HTMLBuilder::makeTitle(const std::string& title) {                         // HTML文件的标题
    filename = title + ".html";                                                 // 将标题作为文件名
    writer.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        writer.open(filename);                                                      // 打开 ofstream
    } catch (const std::ios_base::failure& e) {
        std::cerr << "open " << filename << " failed: " << e.what() << "\n";
        throw;
    }
    writer << "<html><head><title>" << title << "</title></head><body>" << '\n';    // 输出标题
    writer << "<h1>" << title << "</h1>" << '\n';
}

void HTMLBuilder::makeString(const std::string& str) {                          // HTML文件中的字符串
    writer << "<p>" << str << "</p>" << '\n';                                   // 用<p>标签输出
}

void HTMLBuilder::makeItems(const std::vector<std::string>& items) {            // HTML文件中的条目
    writer << "<ul>" << '\n';                                                   // 用<ul>和<li>输出
    for (int i = 0; i < items.size(); i++) {
        writer << "<li>" << items[i] << "</li>" << '\n';
    }
    writer << "</ul>" << '\n';
}

void HTMLBuilder::close() {                                                     // 完成文档
    writer << "</body></html>" << '\n';                                         // 关闭标签
    writer.close();                                                             // 关闭文件
}

std::string HTMLBuilder::getResult() {                                          // 编写完成的文档
    return filename;                                                            // 返回文件名
}
