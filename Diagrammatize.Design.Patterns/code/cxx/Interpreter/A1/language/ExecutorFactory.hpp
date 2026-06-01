#pragma once

#include <memory>

#include "Executor.hpp"

class ExecutorFactory {
public:
    virtual ~ExecutorFactory() = default;
    virtual std::unique_ptr<Executor> createExecutor(const std::string& name) = 0;
};
