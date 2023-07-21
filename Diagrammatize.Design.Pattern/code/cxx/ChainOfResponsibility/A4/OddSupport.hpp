#pragma once

#include "Support.hpp"

class OddSupport : public Support {
public:
    OddSupport(const std::string& name);

    bool resolve(Trouble* trouble) override;
};
