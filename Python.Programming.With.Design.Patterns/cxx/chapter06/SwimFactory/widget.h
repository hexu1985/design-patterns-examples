#pragma once

#include <vector>
#include <QWidget>
#include <QListWidget>

#include "Swimmer.h"

class Widget : public QWidget {
public:
    Widget(QWidget* parent = nullptr); 

private:
    void setupUI(); 
    void onEventSelected(QListWidgetItem* item); 
    void updateSwimmersList(const std::vector<Swimmer>& swimmers);

    QListWidget* listEvents;
    QListWidget* listSwimmers;
};
