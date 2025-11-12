#include "MainWindow.hpp"

#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    InitUI();
}

void MainWindow::InitUI()
{
    // 设置窗口标题和大小
    setWindowTitle("Menu demo");
    setFixedSize(300, 200);

    // 创建菜单栏
    QMenuBar *menuBar = this->menuBar();

    // 创建 File 菜单
    QMenu *fileMenu = menuBar->addMenu("File");

    // 添加 File 菜单项
    QAction *newAction = new QAction("New", this);
    QAction *openAction = new QAction("Open", this);
    QAction *exitAction = new QAction("Exit", this);

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    // 创建 Draw 菜单
    QMenu *drawMenu = menuBar->addMenu("Draw");

    // 添加 Draw 菜单项
    QAction *circleAction = new QAction("Circle", this);
    QAction *squareAction = new QAction("Square", this);

    drawMenu->addAction(circleAction);
    drawMenu->addAction(squareAction);
}
