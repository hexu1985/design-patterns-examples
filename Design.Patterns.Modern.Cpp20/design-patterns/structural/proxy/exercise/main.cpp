/*
- You are given the Person  class and asked to write a ResponsiblePerson
wrapper/proxy that does the following:
- Allows person to drink unless they are younger than 18 (in that case, return
"too young")
- Allows person to drive unless they are younger than 16 (otherwise, "too
young")
- In case of driving while drink, returns "dead"
- The interface of ResponsiblePerson  has to match that of Person , except for
the constructor, which takes an underlying Person object.
*/

#include <iostream>
#include <string>

using namespace std;

class Person {
  friend class ResponsiblePerson;
  int age;

public:
  Person(int age) : age(age) {}

  int get_age() const { return age; }
  void set_age(int age) { this->age = age; }

  string drink() const { return "drinking"; }
  string drive() const { return "driving"; }
  string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson {
public:
  ResponsiblePerson(const Person &person) : person(person) {}

  int get_age() const { return person.get_age(); }
  void set_age(int age) { person.age = age; }

  string drink() const {
    if (person.get_age() <= 18) {
      return "too young";
    }
    return person.drink();
  }
  string drive() const {
    if (person.get_age() <= 16) {
      return "too young";
    }
    return person.drive();
  }

  string drink_and_drive() const { return "dead"; }

private:
  Person person;
};

int main() {
  Person minnor{15};
  cout << minnor.drink() << endl;
  cout << minnor.drive() << endl;
  cout << minnor.drink_and_drive() << endl;

  ResponsiblePerson resonsible_minnor{minnor};
  cout << resonsible_minnor.drink() << endl;
  cout << resonsible_minnor.drive() << endl;
  cout << resonsible_minnor.drink_and_drive() << endl;
}
