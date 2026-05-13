#include "MainWindow.hpp"
#include "Canvas.hpp"
#include "MenuCommand.hpp"
#include "TopMenu.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    InitUI();
}

void MainWindow::InitUI()
{
    setWindowTitle("Menu demo");
    setFixedSize(300, 200);
    
    // Create canvas
    Canvas* canvas = new Canvas(this);
    setCentralWidget(canvas);
    
    // Create menu bar
    QMenuBar* menuBar = this->menuBar();
    
    // Create File menu and its items
    TopMenu fileMenu(this, "File", menuBar);
    fileMenu.addMenuItem(std::make_shared<MenuCommand>(this, "New"));
    fileMenu.addMenuItem(std::make_shared<OpenCommand>(this, "Open"));
    fileMenu.addSeparator();
    fileMenu.addMenuItem(std::make_shared<QuitCommand>(this, "Quit"));
    
    // Create Draw menu and its items
    TopMenu drawMenu(this, "Draw", menuBar);
    drawMenu.addMenuItem(std::make_shared<DrawCircleCommand>(this, canvas, "Circle"));
    drawMenu.addMenuItem(std::make_shared<DrawSquareCommand>(this, canvas, "Square"));

}
