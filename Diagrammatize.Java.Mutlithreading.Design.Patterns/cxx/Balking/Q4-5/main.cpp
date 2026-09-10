#include "TestThread.hpp"

int main() {
    TestThread thread;
    while (true) {
        thread.start();  // 第二次会抛异常
    }
}
