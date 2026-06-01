#pragma once

#include <string>

class Context {
public:
    static const char EOL = -1;  // End Of Line
    Context(const std::string& text);

    std::string nextToken();
    const std::string& currentToken() { return currentToken_; }
    void skipToken(const std::string& token);
    int currentNumber();

private:
    void consume();
    bool isLETTER() {
        return c_ >= 'a' && c_ <= 'z' || c_ >= 'A' && c_ <= 'Z';
    }

    bool isDIGIT() {
        return c_ >= '0' && c_ <= '9';
    }

    void WS();
    std::string NAME();
    std::string NUMBER();

private:
    std::string currentToken_;
    std::string input_;
    int p_ = 0;
    char c_;
};

