#pragma once

#include "Printable.hpp"
#include <string>
#include <unordered_map>
#include <functional>

class PrinterManager {
public:
    using FactoryMethodType = std::function<Printable *()>;
    using FactoryMethodMapType = std::unordered_map<std::string, FactoryMethodType>;

    static Printable* newInstance(const std::string& className);
    static void registerFactoryMethod(const std::string& className, FactoryMethodType factory_method);

private:
    static FactoryMethodMapType& getFactoryMethodMap(); 

public:
    class RegisterFactoryMethodHelper {
    public:
        RegisterFactoryMethodHelper(const std::string& className, FactoryMethodType factory_method);
    };
};

#define REGISTER_PRINTER_CREATER(classname, factory_method) \
    static PrinterManager::RegisterFactoryMethodHelper factory_register_local##classname(#classname, factory_method)

