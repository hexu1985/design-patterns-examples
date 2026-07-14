#pragma once

#include <string>
#include <iostream>

#include "Tool.hpp"

class Pair {
private:
    Tool& lefthand;   // 使用引用，对应Java的final引用
    Tool& righthand;  // 使用引用，对应Java的final引用
    std::mutex mtx;
    
public:
    // 构造函数：使用引用初始化
    Pair(Tool& lefthand, Tool& righthand) 
        : lefthand(lefthand), righthand(righthand) {}
    
    // toString方法
    std::string toString() const {
        return "[ " + lefthand.toString() + " and " + righthand.toString() + " ]";
    }
    
    // 禁止拷贝（因为包含引用成员，拷贝语义不明确）
    Pair(const Pair&) = delete;
    Pair& operator=(const Pair&) = delete;

    std::mutex& getMutex() {
        return mtx;
    }
};
