#include "Person.hpp"
#include "PersonBuilder.hpp"
#include "PersonInfoBuilder.hpp"
#include "PersonJobBuilder.hpp"

#include <iostream>
#include <string>

using namespace std;

int main() {
    PersonJobBuilder pb;
    auto person =
        pb.called("Dmitri")
          .works_as("Programmer") // will not compile
          .build();

    cout << person << endl;

    return 0;
}
