// main.cpp
#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include "MutablePerson.hpp"
#include "ImmutablePerson.hpp"

class CrackerThread {
private:
    MutablePerson& mutablePerson;
    std::thread thread;
    std::atomic<bool> running{true};

public:
    CrackerThread(MutablePerson& mutablePerson) : mutablePerson(mutablePerson) {
    }
    
    ~CrackerThread() {
        running = false;
        if (thread.joinable()) {
            thread.join();
        }
    }
    
    void run() {
        while (running) {
            ImmutablePerson immutable(mutablePerson);
            if (immutable.getName() != immutable.getAddress()) {
                std::cout << std::this_thread::get_id() 
                          << " ***** BROKEN ***** " 
                          << immutable.toString() << std::endl;
            }
        }
    }
    
    void start() {
        thread = std::thread(&CrackerThread::run, this);
    }
};

int main() {
    MutablePerson mutablePerson("start", "start");
    
    // 创建多个CrackerThread
    CrackerThread thread1(mutablePerson);
    CrackerThread thread2(mutablePerson);
    CrackerThread thread3(mutablePerson);
    
    thread1.start();
    thread2.start();
    thread3.start();

    // 持续修改MutablePerson
    for (int i = 0; ; i++) {
        mutablePerson.setPerson(std::to_string(i), std::to_string(i));
    }
    
    return 0;
}
