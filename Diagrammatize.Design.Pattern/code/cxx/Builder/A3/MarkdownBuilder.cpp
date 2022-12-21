#include "MarkdownBuilder.hpp"
#include <iostream>

MarkdownBuilder::~MarkdownBuilder() {
}

void MarkdownBuilder::makeTitle(const std::string& title) {                 // Markdown文件的标题
    filename = title + ".md";                                                 // 将标题作为文件名
    writer.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        writer.open(filename);                                                      // 打开 ofstream
    } catch (const std::ios_base::failure& e) {
        std::cerr << "open " << filename << " failed: " << e.what() << "\n";
        throw;
    }
    writer << "- - -" << '\n';          // 分割线
    writer << "# " << title << '\n';    // 输出标题
    writer << '\n';
}

void MarkdownBuilder::makeString(const std::string& str) {                  // Markdown文件中的字符串
    writer << "> " << str << '\n';                                   // 用<p>标签输出
    writer << '\n';
}

void MarkdownBuilder::makeItems(const std::vector<std::string>& items) {    // Markdown文件中的条目
    for (int i = 0; i < items.size(); i++) {
        writer << "* " << items[i] << '\n';
    }
    writer << '\n';
}

void MarkdownBuilder::close() {                                             // 完成文档
    writer << "- - -" << '\n';                                                  // 分割线
    writer.close();                                                             // 关闭文件
}

std::string MarkdownBuilder::getResult() {                                  // 编写完成的文档
    return filename;                                                            // 返回文件名
}

