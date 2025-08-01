#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>

using namespace std;

struct Address
{
    string street;
    string city;
    int suite;


    friend ostream& operator<<(ostream& os, const Address& obj)
    {
        return os
            << "street: " << obj.street
            << " city: " << obj.city
            << " suite: " << obj.suite;
    }
};

struct Contact
{
    string name;
    Address* address = nullptr;

    friend ostream& operator<<(ostream& os, const Contact& obj)
    {
        return os
            << "name: " << obj.name
            << " address: " << *obj.address;
    }
};

struct EmployeeFactory
{
    static Contact main;
    static Contact aux;

    static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
    {
        //static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
        return NewEmployee(name, suite, main);
    }

    static unique_ptr<Contact> NewAuxOfficeEmployee(string name, int suite)
    {
        return NewEmployee(name, suite, aux);
    }

private:
    static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
    {
        auto result = make_unique<Contact>(proto);
        result->name = name;
        result->address->suite = suite;
        return result;
    }
};

Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

int main()
{
  auto john = EmployeeFactory::NewAuxOfficeEmployee("John Doe", 123);
  auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);

  cout << *john << "\n" << *jane << "\n"; // note the stars here

  getchar();
  return 0;
}
