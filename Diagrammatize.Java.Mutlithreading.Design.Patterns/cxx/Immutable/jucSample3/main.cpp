#include "CopyOnWriteArrayList.hpp"
#include "ReaderThread.hpp"
#include "WriterThread.hpp"

#include <vector>
#include <thread>
#include <chrono>

// 主函数
int main() {
    CopyOnWriteArrayList list;
    
    // 创建线程对象
    WriterThread writer(list);
    ReaderThread reader(list);
    
    // 启动线程
    writer.start();
    reader.start();
    
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
