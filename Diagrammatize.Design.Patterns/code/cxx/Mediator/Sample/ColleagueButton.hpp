#pragma once

#include <QPushButton>

#include "Colleague.hpp"

class Mediator;

class ColleagueButton: public QPushButton, public Colleague {
public:
    Q_OBJECT

private:
    Mediator* mediator;

public:
    ColleagueButton(const std::string& caption, QWidget *parent = 0);
    ~ColleagueButton();

    void setMediator(Mediator* mediator) override;
    void setColleagueEnabled(bool enabled) override;
};
