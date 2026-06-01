
#include <string>

class Banner {
private:
    std::string string;

public:
    Banner(const std::string& string_);
    void showWithParen(); 
    void showWithAster(); 
};
