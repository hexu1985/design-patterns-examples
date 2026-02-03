#pragma once

#include <QWidget>
#include <QLineEdit>

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QLineEdit* entry;
    QLineEdit* frname;
    QLineEdit* lname;
    
public:
    Widget(QWidget* parent = nullptr);
    
private slots:
    void clearPanel();
    void compute();
};

