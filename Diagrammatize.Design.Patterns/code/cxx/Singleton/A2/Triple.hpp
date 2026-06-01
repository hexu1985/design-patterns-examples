#pragma once

#include <string>
#include <iosfwd>

class Triple {
private:
    static Triple triple[3];
    int id;

    Triple(int id);
    Triple(Triple&&) = default;
    Triple(const Triple&) = delete;
    Triple& operator=(const Triple&) = delete;

public:
    static Triple& getInstance(int id);

    std::string toString() const;
};


std::ostream& operator<<(std::ostream&, const Triple&);
