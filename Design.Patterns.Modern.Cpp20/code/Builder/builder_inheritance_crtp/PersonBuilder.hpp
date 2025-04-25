#pragma once

#include "Person.hpp"

class PersonBuilder
{
protected:
    Person person;
public:
    [[nodiscard]] Person build() const {
        return person;
    }
};
