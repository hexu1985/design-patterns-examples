#pragma once

#include <unordered_map>
#include <mutex>
#include "BigChar.hpp"

class BigCharFactory {
private:
    std::unordered_map<std::string, BigChar*> pool;
    std::mutex pool_mutex;
    static BigCharFactory singleton;

    BigCharFactory();

public:
    static BigCharFactory& getInstance();
    BigChar* getBigChar(char charname);
};
