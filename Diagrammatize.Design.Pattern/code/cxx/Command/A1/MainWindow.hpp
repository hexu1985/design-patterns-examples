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
    void onRedButtonClicked();
    void onGreenButtonClicked();
    void onBlueButtonClicked();
    
private:
    void mouseDragged(QMouseEvent *e);
    void setColor(QColor color);

private: 
    DrawCanvas *canvas;
    QPushButton *clearButton;
    QPushButton *redButton;
    QPushButton *greenButton;
    QPushButton *blueButton;
    std::shared_ptr<MacroCommand> history;
};

