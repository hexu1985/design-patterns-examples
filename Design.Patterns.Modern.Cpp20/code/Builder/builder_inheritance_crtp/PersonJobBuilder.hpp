#pragma once

#include "PersonInfoBuilder.hpp"

template <typename TSelf>
class PersonJobBuilder : public PersonInfoBuilder<PersonJobBuilder<TSelf>>
{
public:
    TSelf& works_as(const string& position)
    {
        this->person.position = position;
        return static_cast<TSelf&>(*this);
    }
};

