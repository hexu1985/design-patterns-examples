#include "StringDisplay.hpp"
#include <iostream>

void StringDisplay::open() {                                // 重写的open方法
    printLine();                                    // 调用该类的printLine方法画线
}

void StringDisplay::print() {                               // print方法
    std::cout << "|" << string << "|" << '\n';         // 给保存在字段中的字符串前后分别加上"|"并显示出来 
}

void StringDisplay::close() {                               // close方法
    printLine();                                    // 与open方法一样，调用printLine方法画线
}

void StringDisplay::printLine() {                          // 被open和close方法调用。由于可见性是private，因此只能在本类中被调用 
    std::cout << "+";                          // 显示表示方框的角的"+"
    for (int i = 0; i < width; i++) {               // 显示width个"-"
        std::cout << "-";                      // 组成方框的边框
    }
    std::cout << "+" << std::endl;                        // /显示表示方框的角的"+"
}
