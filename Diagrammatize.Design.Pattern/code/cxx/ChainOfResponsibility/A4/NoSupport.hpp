#pragma once

#include "Support.hpp"

class NoSupport : public Support {
public:
    NoSupport(const std::string& name);

    bool resolve(Trouble* trouble) override;
};
