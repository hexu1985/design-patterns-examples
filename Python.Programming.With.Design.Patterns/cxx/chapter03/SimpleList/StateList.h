#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include "State.h"

class StateList {
private:
    QVector<State> _states;
    
public:
    StateList(const QString& stateFile) {
        QFile file(stateFile);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine().trimmed();
                if (!line.isEmpty()) {
                    _states.append(State(line));
                }
            }
            file.close();
        }
    }
    
    QVector<State> getStateList() const { return _states; }
};

