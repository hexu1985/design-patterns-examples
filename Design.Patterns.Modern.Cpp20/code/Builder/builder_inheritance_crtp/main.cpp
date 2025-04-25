#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonInfoBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonBirthDateBuilder.hpp"

#include <iostream>
#include <string>

using namespace std;

class MyBuilder : public PersonBirthDateBuilder<MyBuilder> {};

int main() {
    MyBuilder mb;
    auto me =
        mb.called("Dmitri")
          .works_as("Programmer")
          .born_on("01/01/1980")
          .build();
    cout << me << endl;
    // name: Dmitri position: Programmer date_of_birth: 01/01/1980

    return 0;
}
