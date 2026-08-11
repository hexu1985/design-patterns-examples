#include "MyThread.hpp"
#include <iostream>

int main() {
    MyThread myThread;
    myThread.start();  // 启动线程
    
    for (int i = 0; i < 10000; i++) {
        std::cout << "Good!";
    }
    
    myThread.join();   // 等待子线程结束
    return 0;
}
