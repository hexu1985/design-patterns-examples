#pragma once

#include "Support.hpp"

class SpecialSupport : public Support {
private:
    int number;

public:
    SpecialSupport(const std::string& name, int number);

    bool resolve(Trouble* trouble) override;
};
