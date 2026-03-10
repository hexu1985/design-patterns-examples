#pragma once

#include <vector>
#include <QWidget>
#include <QListWidget>
#include <QTableWidget>

#include "Swimmer.h"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr); 

private slots:
    void onEventSelected(QListWidgetItem* item); 

private:
    void updateSwimmersList(const std::vector<Swimmer>& swimmers);

    QListWidget* listEvents;
    QTableWidget* tableSwimmers;
};
