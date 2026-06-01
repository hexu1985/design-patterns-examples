#include <QApplication>
#include "LoginFrame.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    LoginFrame* login_frame = new LoginFrame("Mediator Sample");
    login_frame ->show();
    return app.exec();
}
