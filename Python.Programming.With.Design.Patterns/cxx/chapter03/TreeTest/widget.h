#pragma once

#include <QWidget>
#include <QTreeWidget>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

//private slots:

private:
    QTreeWidget* treeWidget;
};
