#pragma once

#include <QApplication>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>

#include "Canvas.hpp"

// Abstract base class for menu commands
class MenuCommand {
public:
    MenuCommand(QMainWindow* root, const QString& label) 
        : root(root), label(label) {}
    virtual ~MenuCommand() = default;
    
    QString getLabel() const { return label; }
    virtual void execute() {}

protected:
    QMainWindow* root;
    QString label;
};

// Menu command for opening files
class OpenCommand : public MenuCommand {
public:
    OpenCommand(QMainWindow* root, const QString& label) 
        : MenuCommand(root, label) {}
    
    void execute() override {
        QString fileName = QFileDialog::getOpenFileName(
            root, "Select file", "", "All Files (*)");
        
        if (!fileName.isEmpty()) {
            QFileInfo fileInfo(fileName);
            root->setWindowTitle(fileInfo.fileName());
        }
    }
};

// Menu command for quitting application
class QuitCommand : public MenuCommand {
public:
    QuitCommand(QMainWindow* root, const QString& label) 
        : MenuCommand(root, label) {}
    
    void execute() override {
        QApplication::quit();
    }
};

// Menu command for drawing circle
class DrawCircleCommand : public MenuCommand {
public:
    DrawCircleCommand(QMainWindow* root, Canvas* canvas, const QString& label) 
        : MenuCommand(root, label), canvas(canvas) {}
    
    void execute() override {
        canvas->drawCircle();
    }

private:
    Canvas* canvas;
};

// Menu command for drawing square
class DrawSquareCommand : public MenuCommand {
public:
    DrawSquareCommand(QMainWindow* root, Canvas* canvas, const QString& label) 
        : MenuCommand(root, label), canvas(canvas) {}
    
    void execute() override {
        canvas->drawSquare();
    }

private:
    Canvas* canvas;
};
