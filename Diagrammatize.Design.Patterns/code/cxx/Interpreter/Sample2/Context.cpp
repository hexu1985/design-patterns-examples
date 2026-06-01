#include "Context.hpp"
#include "ParseException.hpp"

Context::Context(const std::string& text): input_(text) {
    c_ = input_[p_];
    nextToken();
}

void Context::consume() {
    p_++;
    if (p_ >= input_.length()) c_ = EOL;
    else c_ = input_[p_];
}

void Context::WS() {
    while (c_ == ' ' || c_ == '\t' || c_ == '\n' || c_ == '\r')
        consume();
}

std::string Context::nextToken() {
    while (c_ != EOL) {
        switch (c_) {
            case ' ': case '\t': case '\n': case '\r': WS(); continue;
            default:
                if (isLETTER()) return NAME();
                else if (isDIGIT()) return NUMBER();
                else throw ParseException(std::string("invalid charater: ")+c_);
        }
    }

    currentToken_ = "";
    return currentToken_;
}

void Context::skipToken(const std::string& token) {
    if (currentToken_ != token) {
        throw ParseException("Warning: " + token + " is expected, but " + currentToken_ + " is found.");
    }
    nextToken();
}

int Context::currentNumber() {
    int number = 0;
    try {
        number = std::stoi(currentToken_);
    } catch (const std::exception& e) {
        throw ParseException("Warning: " + std::string(e.what()));
    }

    return number;
}

std::string Context::NAME() {
    currentToken_.clear();
    do {
        currentToken_ += c_;
        consume();
    } while (isLETTER());
    return currentToken_;
}

std::string Context::NUMBER() {
    currentToken_.clear();
    do {
        currentToken_ += c_;
        consume();
    } while (isDIGIT());
    return currentToken_;
}
