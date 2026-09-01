#include "Data.hpp"
#include "SaverThread.hpp"
#include "ChangerThread.hpp"

int main() {
    Data data("data.txt", "(empty)");
    
    ChangerThread changer("ChangerThread", data);
    SaverThread saver("SaverThread", data);
    
    changer.start();
    saver.start();
    
    return 0;
}
