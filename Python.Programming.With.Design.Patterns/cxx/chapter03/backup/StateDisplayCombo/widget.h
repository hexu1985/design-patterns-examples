#pragma once

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include "StateList.h"

class Widget : public QWidget {
    Q_OBJECT
    
private:
    QVector<State> _states;
    QComboBox *_comboBox;
    QLabel* _lbState;
    QLabel* _lbAbbrev;
    QLabel* _lbCapital;
    QLabel* _lbFounded;
    
    void loadLabels(const State& state);

public:
    Widget(QWidget* parent, const QVector<State>& states);
    
private slots:
    void onSelectionChanged();
};
