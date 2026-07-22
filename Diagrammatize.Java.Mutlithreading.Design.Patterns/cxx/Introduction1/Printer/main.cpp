#include "Printer.hpp"
#include <iostream>
#include <thread>

int main() {
    // 创建并启动两个子线程
    std::thread t1(Printer("Good!"));
    std::thread t2(Printer("Nice!"));

    // 必须等待两个子线程结束，否则主线程退出会终止整个进程
    t1.join();
    t2.join();

    return 0;
}
