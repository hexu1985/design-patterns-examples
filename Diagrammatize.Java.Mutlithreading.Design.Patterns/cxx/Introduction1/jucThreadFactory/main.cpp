#include "Printer.hpp"
#include <iostream>
#include <thread>

int main() {
    // 创建并启动子线程（相当于 factory.newThread(...).start()）
    std::thread t(Printer("Nice!"));

    // 主线程打印 "Good!" 10000 次
    for (int i = 0; i < 10000; ++i) {
        std::cout << "Good!";
    }

    // 等待子线程完成（模拟非守护线程阻止进程退出）
    t.join();

    return 0;
}
