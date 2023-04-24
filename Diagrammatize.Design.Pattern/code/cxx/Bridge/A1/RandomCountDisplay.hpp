#include "CountDisplay.hpp"
#include "RandomNumber.hpp"

class RandomCountDisplay: public CountDisplay {
private:
    RandomNumber random;

public:
    RandomCountDisplay(DisplayImpl* impl);

    void randomDisplay(int times); 
};
