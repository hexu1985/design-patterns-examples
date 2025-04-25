#pragma once

#include "PersonBuilder.hpp"

class PersonInfoBuilder : public PersonBuilder
{
public:
    PersonInfoBuilder& called(const string& name)
    {
        person.name = name;
        return *this;
    }
};

