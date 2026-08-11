#include "PrintThread.hpp"

int main() {
    // 创建两个 PrintThread 对象
    PrintThread pt1("*");
    PrintThread pt2("+");

    // 启动线程（与 Java 语法几乎一致）
    pt1.start();
    pt2.start();

    // 等待线程结束（C++ 必须显式 join）
    pt1.join();
    pt2.join();

    return 0;
}
