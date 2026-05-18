#pragma once

#include <QString>
#include <QStringList>

class State {
private:
    QString _statename;
    QString _abbrev;
    QString _founded;
    QString _capital;
    
public:
    State(const QString& stateString) {
        QStringList tokens = stateString.split(",");
        if (tokens.size() > 3) {
            _statename = tokens[0].trimmed();
            _abbrev = tokens[1].trimmed();
            _founded = tokens[2].trimmed();
            _capital = tokens[3].trimmed();
        }
    }
    
    QString getStateName() const { return _statename; }
    QString getCapital() const { return _capital; }
    QString getAbbrev() const { return _abbrev; }
    
    QString toString() const { return _statename; }
};

