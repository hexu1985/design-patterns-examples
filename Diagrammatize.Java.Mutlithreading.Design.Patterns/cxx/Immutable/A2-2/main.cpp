#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s = "BAT";
    std::string t = s;  // 复制一份
    std::replace(t.begin(), t.end(), 'B', 'C');  // 将'B'替换为'C'
    
    std::cout << "s = " << s << std::endl;  // 执行replace后的s
    std::cout << "t = " << t << std::endl;  // replace的返回值t
    
    if (s == t) {
        std::cout << "s == t" << std::endl;
    } else {
        std::cout << "s != t" << std::endl;
    }
    
    return 0;
}
