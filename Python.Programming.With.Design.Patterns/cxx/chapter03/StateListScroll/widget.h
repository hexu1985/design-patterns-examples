#pragma once

#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include "StateList.h"

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QVector<State> _states;
    QListWidget* _listWidget;
    QLabel* _lbState;
    QLabel* _lbAbbrev;
    QLabel* _lbCapital;
    
public:
    Widget(QWidget* parent, const QVector<State>& states);
    
private slots:
    void onSelectionChanged(); 
};
