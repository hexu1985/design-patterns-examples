#include "IncrementalNumberGenerator.hpp"
#include "DigitObserver.hpp"
#include "GraphObserver.hpp"

int main() {
    NumberGenerator* generator = new IncrementalNumberGenerator(10, 50, 5);  
    Observer* observer1 = new DigitObserver();
    Observer* observer2 = new GraphObserver();
    generator->addObserver(observer1);
    generator->addObserver(observer2);
    generator->execute();

    return 0;
}
