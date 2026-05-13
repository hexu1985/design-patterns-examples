#pragma once

#include <QObject>

class DButton;

// 中介者类，对应 Python 中的 Mediator
class Mediator : public QObject {
    Q_OBJECT
private:
    DButton* quitButton = nullptr;

public:
    Mediator(QWidget* parent = nullptr);
    void setQuitButton(DButton* button); 

public slots:
    void sclicked(); 
};
