#include "AbstractDisplay.hpp"
#include <string>

class StringDisplay : public AbstractDisplay {    // StringDisplay也是AbstractDisplay的子类 
private:
    std::string string;                              // 需要显示的字符串
    int width;                                  // 以字节为单位计算出的字符串长度

public:
    StringDisplay(const std::string& string_):      // 构造函数中接收的字符串被
        string(string_),                           // 保存在字段中
        width(string_.length()) {                // 同时将字符串的字节长度也保存在字段中，以供后面使用 
    }

    void open() override; 
    void print() override;
    void close() override; 

private:
    void printLine(); 
};

