#include "MainWindow.hpp"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <iostream>
#include <QApplication>
#include "drawer/DrawCommand.hpp"

int
main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    MainWindow m("Command Pattern Sample");
    m.show();
    return app.exec();
}
