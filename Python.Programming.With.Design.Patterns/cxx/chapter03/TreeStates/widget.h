#pragma once

#include <QWidget>
#include <QTreeWidget>
#include "StateList.h"

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QTreeWidget* treeWidget;
    
public:
    Widget(QWidget* parent, const QVector<State>& states);
    
//private slots:
};
