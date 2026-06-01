#include "PrinterManager.hpp"

PrinterManager::FactoryMethodMapType& PrinterManager::getFactoryMethodMap() {
    static FactoryMethodMapType factory_method_map{};
    return factory_method_map;
}

void PrinterManager::registerFactoryMethod(const std::string& className, FactoryMethodType factory_method) {
    auto& factory_method_map = getFactoryMethodMap();
    factory_method_map[className] = factory_method;
}

Printable* PrinterManager::newInstance(const std::string& className) {
    auto& factory_method_map = getFactoryMethodMap();
    auto iter = factory_method_map.find(className);
    if (iter == factory_method_map.end()) {
        return nullptr;
    }
    auto factory_method = iter->second;
    return factory_method();
}

PrinterManager::RegisterFactoryMethodHelper::RegisterFactoryMethodHelper(
        const std::string& className, PrinterManager::FactoryMethodType factory_method) {
    PrinterManager::registerFactoryMethod(className, factory_method);
}
