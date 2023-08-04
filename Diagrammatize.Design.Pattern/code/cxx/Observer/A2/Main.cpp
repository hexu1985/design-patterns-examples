#include <QApplication>

#include "RandomNumberGenerator.hpp"
#include "DigitObserver.hpp"
#include "GraphObserver.hpp"
#include "FrameObserver.hpp"
#include <thread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FrameObserver* frame = new FrameObserver();
    frame->setWindowTitle(QObject::tr("Frame Observer"));
    frame->show();

    NumberGenerator* generator = new RandomNumberGenerator();
    Observer* observer1 = new DigitObserver();
    Observer* observer2 = new GraphObserver();
    Observer* observer3 = frame;
    generator->addObserver(observer1);
    generator->addObserver(observer2);
    generator->addObserver(observer3);

    std::thread([generator]() {
            generator->execute();
            }).detach();

    return app.exec();
}
