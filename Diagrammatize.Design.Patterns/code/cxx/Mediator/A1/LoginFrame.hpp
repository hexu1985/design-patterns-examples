#pragma once

#include <QWidget>

#include "ColleagueCheckbox.hpp"
#include "ColleagueTextField.hpp"
#include "ColleagueButton.hpp"
#include "Mediator.hpp"

class LoginFrame: public QWidget, public Mediator {
public:
    Q_OBJECT

private:
    ColleagueCheckbox* checkGuest;
    ColleagueCheckbox* checkLogin;
    ColleagueTextField* textUser;
    ColleagueTextField* textPass;
    ColleagueButton* buttonOk;
    ColleagueButton* buttonCancel;

public:
    LoginFrame(const std::string& title, QWidget *parent = 0);
    ~LoginFrame();

    void createColleagues() override;
    void colleagueChanged() override;

private:
    void userpassChanged(); 

private slots:
    void actionPerformed(); 
};
