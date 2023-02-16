#include "IDCardFactory.hpp"
#include "IDCard.hpp"

Product* IDCardFactory::createProduct(const std::string& owner) {
    return new IDCard(owner, serial++);
}

void IDCardFactory::registerProduct(Product* product) {
    IDCard* card = static_cast<IDCard *>(product);
    database[card->getSerial()] = card->getOwner();
}

const std::unordered_map<int, std::string>& IDCardFactory::getDatabase() {
    return database;
}
