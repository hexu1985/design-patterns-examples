#include <QApplication>
#include "Director.hpp"
#include "FrameBuilder.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FrameBuilder *framebuilder = new FrameBuilder();
    Director director(framebuilder);
    director.construct();

    QMainWindow *frame = framebuilder->getResult();
    frame->show();

    return app.exec();
}
