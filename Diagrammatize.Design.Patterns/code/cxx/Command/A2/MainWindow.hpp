#pragma once

#include <memory>
#include <QPushButton>
#include "drawer/DrawCanvas.hpp"
#include "command/MacroCommand.hpp"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(const QString& title, QWidget *parent=0);
    
public slots:
    bool eventFilter(QObject*,QEvent*);
    void onClearButtonClicked();
    void onUndoButtonClicked();
    
private:
    void mouseDragged(QMouseEvent *e);

private: 
    DrawCanvas *canvas;
    QPushButton *clearButton;
    QPushButton *undoButton;
    std::shared_ptr<MacroCommand> history;
};


