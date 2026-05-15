#pragma once

#include <QWidget>
#include <QListWidget>
#include "StateList.h"

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QVector<State> _states;
    QListWidget* _listWidget;
    
public:
    Widget(QWidget* parent, const QVector<State>& states);
    
private slots:
    void onSelectionChanged(); 
};
