#pragma once

#include <string>
#include <vector>

#include "Executor.hpp"
#include "ExecutorFactory.hpp"

class Context: public ExecutorFactory {
private:
    std::vector<std::string> tokens_;
    size_t currentIndex_;
    std::string currentToken_;
    ExecutorFactory* factory_=nullptr;

public:
    Context(const std::string& text); 

    std::string nextToken(); 

    const std::string& currentToken() const;

    void skipToken(const std::string& token); 

    int currentNumber(); 

    void setExecutorFactory(ExecutorFactory* factory); 

    std::unique_ptr<Executor> createExecutor(const std::string& name) override; 
};
