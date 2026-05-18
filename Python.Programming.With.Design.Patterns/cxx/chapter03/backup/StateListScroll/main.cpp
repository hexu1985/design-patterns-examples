#include <QApplication>
#include <QMainWindow>
#include <QDir>
#include "StateList.h"
#include "widget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // 获取数据文件路径（假设数据文件在可执行文件同一目录）
    QString dataFile = QDir::currentPath() + "/States.txt";
    
    // 创建州列表
    StateList sl(dataFile);
    
    // 创建主窗口
    Widget w(nullptr, sl.getStateList());
    w.setWindowTitle("Simple State List");
    w.show();
    
    return app.exec();
}
