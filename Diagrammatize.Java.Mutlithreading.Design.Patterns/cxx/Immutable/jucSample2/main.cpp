#include "ReaderThread.hpp"
#include "WriterThread.hpp"

#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

// 主函数
int main() {
    std::vector<int> list;
    std::mutex mutex;
    
    // 创建线程对象
    WriterThread writer(list, mutex);
    ReaderThread reader(list, mutex);
    
    // 启动线程
    writer.start();
    reader.start();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
