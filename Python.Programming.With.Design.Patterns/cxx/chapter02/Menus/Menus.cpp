#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>

void InitUI(QMainWindow* root) {
    // 创建菜单栏
    QMenuBar* menubar = root->menuBar();
    root->setWindowTitle("Menu demo");
    root->setFixedSize(300, 200);

    // 创建 File 菜单（tearoff=0 忽略，Qt 默认无分离）
    QMenu* filemenu = new QMenu("File", menubar);
    menubar->addMenu(filemenu);
    filemenu->addAction("New");
    filemenu->addAction("Open");
    filemenu->addSeparator();
    filemenu->addAction("Exit");

    // 创建 Draw 菜单
    QMenu* drawmenu = new QMenu("Draw", menubar);
    menubar->addMenu(drawmenu);
    drawmenu->addAction("Circle");
    drawmenu->addAction("Square");
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow root;
    InitUI(&root);
    root.show();
    return app.exec();   // 代替 mainloop()
}