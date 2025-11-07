#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class Widget : public QWidget {
    Q_OBJECT

private:
    QLineEdit *nmEntry;
    QLabel *cLabel;

public:
    Widget(QWidget *parent = nullptr); 

private slots:
    void getName(); 
};

