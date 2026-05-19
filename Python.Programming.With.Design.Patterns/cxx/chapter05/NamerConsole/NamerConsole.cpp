#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Base Namer class
class Namer {
protected:
    std::string last;
    std::string first;

public:
    Namer() : last(""), first("") {}
    virtual ~Namer() {}
    
    std::string getLast() const { return last; }
    std::string getFirst() const { return first; }
};

// Derived namer class for First <space> Last
class FirstFirst : public Namer {
public:
    FirstFirst(const std::string& namestring) {
        size_t i = namestring.find(" "); // find space between names
        if (i != std::string::npos && i > 0) {
            std::istringstream iss(namestring);
            iss >> first >> last;
        } else {
            last = namestring;
        }
    }
};

// Derived Namer class for Last <comma> First
class LastFirst : public Namer {
public:
    LastFirst(const std::string& namestring) {
        size_t i = namestring.find(","); // find comma between names
        if (i != std::string::npos && i > 0) {
            // Split by comma
            size_t commaPos = namestring.find(',');
            last = namestring.substr(0, commaPos);
            first = namestring.substr(commaPos + 1);
            
            // Trim whitespace
            size_t firstNonSpace = first.find_first_not_of(" ");
            if (firstNonSpace != std::string::npos) {
                first = first.substr(firstNonSpace);
            }
            
            // Trim whitespace from end of last
            size_t lastNonSpace = last.find_last_not_of(" ");
            if (lastNonSpace != std::string::npos) {
                last = last.substr(0, lastNonSpace + 1);
            }
        } else {
            last = namestring;
        }
    }
};

/**
 * The NameFactory returns an instance of the Namer class that separates first and last names
 * depending on whether a comma is present
 */
class NamerFactory {
private:
    std::string name;

public:
    NamerFactory(const std::string& namestring) : name(namestring) {}
    
    Namer* getNamer() {
        size_t i = name.find(","); // if it finds a comma
        if (i != std::string::npos && i > 0) {
            return new LastFirst(name); // get the LastFirst class
        } else {
            return new FirstFirst(name); // else get the FirstFirst
        }
    }
};

class Builder {
public:
    void compute() {
        std::string name;
        while (true) {
            std::cout << "Enter name: ";
            std::getline(std::cin, name); // get the name string
            
            if (name == "quit") {
                break;
            }
            
            // get the Namer Factory and then the namer class
            NamerFactory namerFact(name); // get namer factory
            Namer* namer = namerFact.getNamer(); // get namer
            
            std::cout << namer->getFirst() << " " << namer->getLast() << std::endl;
            
            delete namer; // Clean up allocated memory
        }
    }
};

int main() {
    Builder bld;
    bld.compute();
    return 0;
}
