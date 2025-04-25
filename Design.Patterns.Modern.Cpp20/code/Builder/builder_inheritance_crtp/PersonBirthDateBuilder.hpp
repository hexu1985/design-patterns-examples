#pragma once

#include "PersonJobBuilder.hpp"

template <typename TSelf>
class PersonBirthDateBuilder
    : public PersonJobBuilder<PersonBirthDateBuilder<TSelf>>
{
public:
    TSelf& born_on(const string& date_of_birth)
    {
        this->person.date_of_birth = date_of_birth;
        return static_cast<TSelf&>(*this);
    }
};
