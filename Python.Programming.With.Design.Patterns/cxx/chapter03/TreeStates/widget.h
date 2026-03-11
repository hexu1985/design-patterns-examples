#pragma once

#include <QWidget>
#include <QTableWidget>
#include "StateList.h"

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QTableWidget* tableWidget;
    
public:
    Widget(QWidget* parent, const QVector<State>& states);
    
//private slots:
};
