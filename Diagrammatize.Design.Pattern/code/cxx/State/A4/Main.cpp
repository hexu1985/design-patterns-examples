#include <QApplication>
#include <thread>
#include <chrono>

#include "SafeFrame.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SafeFrame* frame = new SafeFrame;
    frame->show();
    std::thread([frame]() {
            for (int hour = 0; hour < 24; hour++) {
                frame->setClock(hour);
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
            }).detach();
    return app.exec();
}

