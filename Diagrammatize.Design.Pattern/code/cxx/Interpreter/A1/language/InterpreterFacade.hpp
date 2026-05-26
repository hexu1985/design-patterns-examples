#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "Executor.hpp"
#include "ExecutorFactory.hpp"
#include "Context.hpp"
#include "Node.hpp"

class InterpreterFacade : public Executor {
private:
    ExecutorFactory* factory_=nullptr;  // 改用智能指针管理
    std::unique_ptr<Context> context_;
    std::unique_ptr<Node> programNode_;  // 假设 ProgramNode 继承自 Node
    
public:
    // 构造函数：接受 ExecutorFactory 的所有权
    explicit InterpreterFacade(ExecutorFactory* factory);
    
    bool parse(const std::string& text); 
    
    void execute() override; 
};
