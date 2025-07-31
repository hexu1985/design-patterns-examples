#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

using namespace std;

struct Address {
    string street, city;
    int suite;

    Address(const string &street, const string &city, int suite)
        : street(street), city(city), suite(suite) {}

    friend ostream &operator<<(ostream &os, const Address &address) {
        return os << address.str();
    }

    virtual Address* clone()
    {
        return new Address{street, city, suite};
    }

    virtual std::string str() const {
        ostringstream os;
        os << "street: " << street << " city: " << city
            << " suite: " << suite;
        return os.str();
    }
};

class ExtendedAddress : public Address
{
public:
    string country, postcode;
    ExtendedAddress(const string &street, const string &city,
            const int suite, const string &country,
            const string &postcode)
        : Address(street, city, suite)
          , country{country}, postcode{postcode} {}

    ExtendedAddress* clone() override {
    #if 0
        return new ExtendedAddress(street, city, suite,
                country, postcode);
    #else
        return new ExtendedAddress(*this);
    #endif
    }

    virtual std::string str() const {
        ostringstream os;
        os << this->Address::str() << " country: " << country
            << " postcode: " << postcode;
        return os.str();
    }
};


int main() {
    ExtendedAddress ea{"123 West Dr", "London", 123, "UK", "SW101EG"};
    Address& a = ea; // upcast
    auto cloned = a.clone();

    cout << *cloned << endl;

    return 0;
}
