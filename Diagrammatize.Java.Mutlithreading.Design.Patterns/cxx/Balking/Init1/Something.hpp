#include <mutex>

class Something {
public:
    void init() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (initialized_) {
            return;
        }
        doInit();
        initialized_ = true;
    }

private:
    void doInit() {
        // 实际的初始化处理
    }

    bool initialized_ = false;
    std::mutex mutex_;
};
