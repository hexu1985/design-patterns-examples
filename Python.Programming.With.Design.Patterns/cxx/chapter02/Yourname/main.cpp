#include <QtWidgets/QApplication>
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    Widget w;
    w.setWindowTitle("Name App");
    w.resize(300, 200);
    w.show();
    
    return app.exec();
}

