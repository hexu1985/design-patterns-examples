#pragma once

#include <QCheckBox>

#include "Colleague.hpp"

class Mediator;

class ColleagueCheckbox: public QCheckBox, public Colleague {
public:
    Q_OBJECT

private:
    Mediator* mediator;

public:
    ColleagueCheckbox(const std::string& caption, QWidget *parent = 0);
    ~ColleagueCheckbox();

    void setMediator(Mediator* mediator) override;
    void setColleagueEnabled(bool enabled) override;
};


