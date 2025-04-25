#pragma once

#include "PersonInfoBuilder.hpp"

class PersonJobBuilder : public PersonInfoBuilder
{
public:
    PersonJobBuilder& works_as(const string& position)
    {
        person.position = position;
        return *this;
    }
};

