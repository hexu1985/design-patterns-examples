#include "Factory.hpp"
#include "Singleton.hpp"

#include <unordered_map>

namespace {

class FactoryManager: public Singleton<FactoryManager> {
private:
    std::unordered_map<std::string, std::function<Factory*()>> factory_set;

public:
    FactoryManager() {}

    void registerFactory(const std::string& classname, std::function<Factory*()> newFactory) {
        factory_set[classname] = newFactory;
    }

    Factory* createFactory(const std::string& classname) {
        auto iter = factory_set.find(classname);
        if (iter == factory_set.end()) {
            return nullptr;
        }
        auto newFactory = factory_set[classname];
        return newFactory();
    }
};

}   // namespace

FactoryRegister::FactoryRegister(const std::string& classname, std::function<Factory*()> newFactory) {
    FactoryManager::getInstance().registerFactory(classname, newFactory);
}

Factory* Factory::getFactory(const std::string& classname) {
    return FactoryManager::getInstance().createFactory(classname);
}

Factory::~Factory() {
}
