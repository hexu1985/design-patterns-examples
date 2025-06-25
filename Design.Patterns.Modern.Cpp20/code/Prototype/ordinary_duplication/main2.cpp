#include <iostream>
#include <ostream>
#include <string>

using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
        : street(street), city(city), suite(suite) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        return os << "street: " << address.street << " city: " << address.city
            << " suite: " << address.suite;
    }
};

struct Contact {
    string name;
    Address *address;

    Contact(const string &name, Address *address)
        : name(name), address(address) {}

    ~Contact() { delete address; }

    friend ostream &operator<<(ostream &os, const Contact &contact) {
        return os << "name: " << contact.name << " address: " << *contact.address;
    }
};

int main() {
    // here is the prototype:
    Contact worker{"", new Address{"123 East Dr", "London", 0}};

    // make a copy of prototype and customize it
    Contact john = worker;
    john.name = "John Doe";
    john.address->suite = 10;

    cout << john << endl;

    return 0;
}
