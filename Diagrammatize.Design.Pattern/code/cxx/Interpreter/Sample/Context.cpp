#include "Context.hpp"
#include "ParseException.hpp"
#include <sstream>

namespace {

std::vector<std::string> tokenize(const std::string& text) {
    std::vector<std::string> result;
    std::istringstream iss(text);
    std::string token;

    while (iss >> token) {
        result.push_back(token);
    }
    return result;
}

}   // namespace

Context::Context(const std::string& text) {
    tokens_ = tokenize(text);
    currentIndex_ = 0;
    nextToken();
}

std::string Context::nextToken() {
    if (currentIndex_ < tokens_.size()) {
        currentToken_ = tokens_[currentIndex_];
        currentIndex_++;
    } else {
        currentToken_ = "";
    }
    return currentToken_;
}

const std::string& Context::currentToken() const {
    return currentToken_;
}

void Context::skipToken(const std::string& token) {
    if (token != currentToken_) {
        throw ParseException("Warning: " + token + " is expected, but " + currentToken_ + " is found.");
    }
    nextToken();
}

int Context::currentNumber() {
    if (currentToken_.empty()) {
        throw ParseException("Warning: Empty token");
    }

    try {
        size_t pos;
        int number = std::stoi(currentToken_, &pos);

        // 检查是否整个字符串都被转换了
        if (pos != currentToken_.length()) {
            throw ParseException("Warning: Invalid number format: " + currentToken_);
        }
        return number;
    } catch (const std::invalid_argument& e) {
        throw ParseException("Warning: Invalid argument: " + currentToken_);
    } catch (const std::out_of_range& e) {
        throw ParseException("Warning: Number out of range: " + currentToken_);
    }
}
