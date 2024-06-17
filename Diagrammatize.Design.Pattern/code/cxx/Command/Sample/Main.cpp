#include "MainWindow.hpp"
#include <QApplication>

int
main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    MainWindow m("Command Pattern Sample");
    m.show();
    return app.exec();
}
