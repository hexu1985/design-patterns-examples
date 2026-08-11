#pragma once

#include <iostream>
#include <string>
#include <mutex>

class Bank {
private:
    std::string name;
    int money;
    std::mutex mtx;

public:
    // 构造函数，使用成员初始化列表
    Bank(const std::string& name, int money) : name(name), money(money) {}

    void deposit(int m) {
        std::lock_guard<std::mutex> lock(mtx);
        money += m;
    }

    bool withdraw(int m) {
        std::lock_guard<std::mutex> lock(mtx);
        if (money >= m) {
            money -= m;
            check();        // 调用私有成员函数
            return true;
        } else {
            return false;
        }
    }

    // 常量成员函数，不修改对象状态
    std::string getName() const {
        return name;
    }

private:
    // 私有辅助函数
    void check() {
        if (money < 0) {
            std::cout << "可用余额为负数! money = " << money << std::endl;
        }
    }
};
