#pragma once

#include <QLineEdit>

#include "Colleague.hpp"

class Mediator;

class ColleagueTextField: public QLineEdit, public Colleague {
public:
    Q_OBJECT

private:
    Mediator* mediator;

public:
    ColleagueTextField(const std::string& caption, QWidget *parent = 0);
    ~ColleagueTextField();

    void setMediator(Mediator* mediator) override;
    void setColleagueEnabled(bool enabled) override;

private slots:
    void textValueChanged(const QString &text);
};
