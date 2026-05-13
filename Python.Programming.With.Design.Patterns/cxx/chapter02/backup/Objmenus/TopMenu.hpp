#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <memory>

// Represents the top menu item in each column
class TopMenu {
public:
    TopMenu(QMainWindow* root, const QString& label, QMenuBar* menuBar) {
        menu = menuBar->addMenu(label);
        this->root = root;
    }
    
    void addMenuItem(std::shared_ptr<MenuCommand> command) {
        QAction* action = new QAction(command->getLabel(), root);
        QObject::connect(action, &QAction::triggered, 
                        [command]() { command->execute(); });
        menu->addAction(action);
    }
    
    void addSeparator() {
        menu->addSeparator();
    }

private:
    QMainWindow* root;
    QMenu* menu;
};