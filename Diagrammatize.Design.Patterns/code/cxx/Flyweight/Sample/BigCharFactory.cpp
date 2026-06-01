#include "BigCharFactory.hpp"

BigCharFactory::BigCharFactory() {
}

BigCharFactory& BigCharFactory::getInstance() {
    static BigCharFactory singleton;
    return singleton;
}

BigChar* BigCharFactory::getBigChar(char charname) {
    std::lock_guard<std::mutex> lck(pool_mutex);
    BigChar* bc = pool[std::string("") + charname];
    if (bc == nullptr) {
        bc = new BigChar(charname);
        pool[std::string("") + charname] = bc;
    }
    return bc;
}
