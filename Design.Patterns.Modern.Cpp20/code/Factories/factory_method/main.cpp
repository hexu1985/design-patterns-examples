#include "SolidWall.h"
#include <iostream>

using namespace std;

int main() {
    const auto main_wall = SolidWall::create_main({0,0}, {0,3000},
            2700, 3000);
    cout << main_wall << "\n";
    // start: (0,0) end: (0,3000) elevation: 2700 height: 3000
    // width: 375 material: aerated concrete
}
