#pragma once

#include <ostream>
#include <string>

using namespace std;

class Person
{
public:
    string name, position, date_of_birth;
    friend ostream& operator<<(ostream& os, const Person& obj)
    {
        return os
            << "name: " << obj.name
            << " position: " << obj.position
            << " date_of_birth: " << obj.date_of_birth;
    }
};
