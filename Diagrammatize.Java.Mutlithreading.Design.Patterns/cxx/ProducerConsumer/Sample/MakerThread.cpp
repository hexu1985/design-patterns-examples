#include "MakerThread.hpp"

// 静态成员定义
int MakerThread::id_ = 0;
std::mutex MakerThread::id_mutex_;
