#pragma once

#include "PersonBuilder.hpp"

template <typename TSelf>
class PersonInfoBuilder : public PersonBuilder
{
public:
    TSelf& called(const string& name)
    {
        person.name = name;
        return static_cast<TSelf&>(*this);
        // alternatively, *static_cast<TSelf*>(this)
    }
};

