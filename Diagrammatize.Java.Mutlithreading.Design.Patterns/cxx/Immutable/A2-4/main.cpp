#include "UserInfo.hpp"

#include <iostream>
#include <string>
#include <memory>

int main() {
    // 创建实例
    UserInfo userinfo("Alice", "Alaska");
    
    // 显示
    std::cout << "userinfo = " << userinfo.toString() << std::endl;
    
    std::string& info = userinfo.getInfo();
    // 注意：C++字符串索引从0开始，"Alice"在位置12-16
    info.replace(12, 5, "Bobby");  // 从位置12开始替换5个字符
    
    // 再次显示
    std::cout << "userinfo = " << userinfo.toString() << std::endl;
    
    return 0;
}
