#pragma once

#include "Trouble.hpp"
#include <iosfwd>

class Support {
private:
    std::string name;
    Support* next;

public:
    Support(const std::string& name);

    Support* setNext(Support* next);

    void support(Trouble* trouble);

    std::string toString() const;

protected:
    virtual bool resolve(Trouble* trouble) = 0;

    void done(Trouble* trouble);

    void fail(Trouble* trouble);
};

std::ostream& operator<<(std::ostream&, const Support&);
