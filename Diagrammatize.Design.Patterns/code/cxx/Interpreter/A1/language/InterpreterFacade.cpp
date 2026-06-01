#include "InterpreterFacade.hpp"
#include "ProgramNode.hpp"
#include "ParseException.hpp"
#include "ExecuteException.hpp"

InterpreterFacade::InterpreterFacade(ExecutorFactory* factory) 
    : factory_(factory) {
}
    
bool InterpreterFacade::parse(const std::string& text) {
    bool ok = true;

    // 创建 Context 并设置 factory
    context_ = std::make_unique<Context>(text);
    context_->setExecutorFactory(factory_);

    // 创建 ProgramNode
    programNode_ = std::make_unique<ProgramNode>();

    try {
        programNode_->parse(*context_);
        std::cout << programNode_->toString() << std::endl;
    } catch (const ParseException& e) {
        std::cerr << e.what() << std::endl;
        ok = false;
    }

    return ok;
}

void InterpreterFacade::execute() {
    try {
        if (programNode_) {
            programNode_->execute();
        }
    } catch (const ExecuteException& e) {
        std::cerr << e.what() << std::endl;
    }
}
