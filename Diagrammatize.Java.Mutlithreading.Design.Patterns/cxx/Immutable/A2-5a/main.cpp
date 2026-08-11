#include "Point.hpp"
#include "Line.hpp"

#include <iostream>

int main() {
    // 创建实例
    auto p1 = std::make_shared<Point>(0, 0);
    auto p2 = std::make_shared<Point>(100, 0);
    Line line(p1, p2);
    
    // 显示
    std::cout << "line = " << line.toString() << std::endl;
    
    // 修改状态 - 这会同时修改line中的点
    p1->x = 150;
    p2->x = 150;
    p2->y = 250;
    
    // 再次显示 - line也改变了
    std::cout << "line = " << line.toString() << std::endl;
    
    return 0;
}
