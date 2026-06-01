#include "CharDisplay.hpp"
#include <iostream>

void CharDisplay::open() {                            // 在父类中是抽象方法，此处重写该方法  
    std::cout << "<<";                     // 显示开始字符"<<"
}

void CharDisplay::print() {                           // 同样地重写print方法。该方法会在display中被重复调用
    std::cout << ch;                                // 显示保存在字段ch中的字符
}

void CharDisplay::close() {                           // 同样地重写close方法
    std::cout << ">>" << std::endl;                 // 显示结束字符">>"
}
