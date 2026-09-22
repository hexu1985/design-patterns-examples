#include <string>
#include <random>
#include <thread>
#include <chrono>
#include <iostream>

class Table;  // 前向声明

class EaterThread {
public:
    EaterThread(const std::string& name, Table& table, long seed)
        : name_(name), table_(table), random_(seed) {}

    ~EaterThread() {
        join();
    }

    // 启动线程
    void start() {
        thread_ = std::thread(&EaterThread::run, this);
    }

    // 等待线程结束
    void join() {
        if (thread_.joinable()) {
            thread_.join();
        }
    }

    void run() {
        current_thread::set_thread_name(name_);
        try {
            while (true) {
                std::string cake = table_.take();
                // Java: Thread.sleep(random.nextInt(1000));
                int ms = random_() % 1000;  // 或 std::uniform_int_distribution
                std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            }
        } catch (...) {
            // 对应 Java 的 InterruptedException 处理（此处为空）
        }
    }

private:
    std::string name_;
    Table& table_;
    std::mt19937 random_;
    std::thread thread_;
};
