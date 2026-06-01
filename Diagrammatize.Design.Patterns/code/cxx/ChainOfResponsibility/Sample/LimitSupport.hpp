#pragma once

#include "Support.hpp"

class LimitSupport : public Support {
private:
    int limit;

public:
    LimitSupport(const std::string& name, int limit);

    bool resolve(Trouble* trouble) override;
};
