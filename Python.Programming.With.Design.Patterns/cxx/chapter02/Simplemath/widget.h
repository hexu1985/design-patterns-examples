#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private slots:
    void getSum(); 

private:
    QLineEdit *xEntry;
    QLineEdit *yEntry;
    QPushButton *okButton;
    QLabel *cLabel;
};
