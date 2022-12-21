#include "TextBuilder.hpp"

TextBuilder::~TextBuilder() {
}

void TextBuilder::makeTitle(const std::string& title) {     // 纯文本的标题
    buffer += "==============================\n";               // 装饰线
    buffer += "『" + title + "』\n";                            // 为标题加上『』
    buffer += "\n";                                             // 换行
}

void TextBuilder::makeString(const std::string& str) {      // 纯文本的字符串
    buffer += "■" + str + "\n";                                // 为字符串添加■
    buffer += "\n";                                             // 换行
}

void TextBuilder::makeItems(const std::vector<std::string>& items) {    // 纯文本的条目
    for (int i = 0; i < items.size(); i++) {
        buffer += "　・" + items[i] + "\n";                     // 为条目添加・
    }
    buffer += "\n";                                             // 换行
}

void TextBuilder::close() {                             // 完成文档
    buffer += "==============================\n";               // 装饰线
}

std::string TextBuilder::getResult() {                  // 完成的文档
    return buffer;
}
