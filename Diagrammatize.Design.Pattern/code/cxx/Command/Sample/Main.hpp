#pragma once

#include <memory>
#include <QPushButton>
#include "drawer/DrawCanvas.hpp"
#include "command/MacroCommand.hpp"

class Main : public QWidget
{
    Q_OBJECT
public:
    Main(const QString& title, QWidget *parent=0);
    
public slots:
    bool eventFilter(QObject*,QEvent*);
    void onClearButtonClicked();
    
private:
    void mouseDragged(QMouseEvent *e);

private: 
    DrawCanvas *canvas;
    QPushButton *clearButton;
    std::shared_ptr<MacroCommand> history;
};


