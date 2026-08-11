#include "Point.hpp"
#include "Line.hpp"

#include <iostream>

int main() {
    // 创建实例
    Point p1(0, 0);
    Point p2(100, 0);
    Line line(p1, p2);

    // 显示
    std::cout << "line = " << line.toString() << std::endl;

    // 修改状态 - 注意：这会修改p1和p2，但不会影响line
    p1.x = 150;
    p2.x = 150;
    p2.y = 250;

    // 再次显示 - line保持不变
    std::cout << "line = " << line.toString() << std::endl;

    return 0;
}
