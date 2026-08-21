#include <iostream>
#include <string>
#include <chrono>
#include <mutex>

const long CALL_COUNT = 1000000L;

class NotSynch {
private:
    const std::string name = "NotSynch";
public:
    std::string toString() {
        return "[ " + name + "]";
    }
};

class Synch {
private:
    const std::string name = "Synch";
    std::mutex mtx;
public:
    std::string toString() {
        std::lock_guard<std::mutex> lock(mtx);
        return "[ " + name + "]";
    }
};

template<typename T>
void trial(const std::string& msg, long long count, T& obj) {
    std::cout << msg << ": BEGIN" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    
    for (long long i = 0; i < count; i++) {
        obj.toString();
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    
    std::cout << msg << ": END" << std::endl;
    std::cout << "Elapsed time = " << elapsed << "msec." << std::endl;
}

int main() {
    NotSynch notSynch;
    Synch synch;
    
    trial("NotSynch", CALL_COUNT, notSynch);
    trial("Synch", CALL_COUNT, synch);
    
    return 0;
}
