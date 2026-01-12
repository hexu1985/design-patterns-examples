#pragma once

#include <string>
#include <vector>

class Context {
private:
    std::vector<std::string> tokens_;
    size_t currentIndex_;
    std::string currentToken_;

public:
    Context(const std::string& text); 

    std::string nextToken(); 

    const std::string& currentToken() const;

    void skipToken(const std::string& token); 

    int currentNumber(); 
};
