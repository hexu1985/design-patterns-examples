#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s = "BAT";
    std::replace(s.begin(), s.end(), 'B', 'C');
    std::cout << s << std::endl;
    return 0;
}
