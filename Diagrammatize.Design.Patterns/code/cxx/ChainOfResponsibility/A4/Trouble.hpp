#pragma once

#include <string>
#include <iosfwd>

class Trouble {
private:
    int number;

public:
    Trouble(int number); 

    int getNumber() const;

    std::string toString() const;
};

std::ostream& operator<<(std::ostream&, const Trouble&);
