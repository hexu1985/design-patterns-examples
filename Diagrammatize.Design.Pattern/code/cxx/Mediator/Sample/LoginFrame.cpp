#include "LoginFrame.hpp"

#include <QGridLayout>
#include <QButtonGroup>
#include <QLabel>

LoginFrame::LoginFrame(const std::string& title, QWidget *parent): QWidget(parent) {
    setWindowTitle(title.c_str());
    
    // 生成各个Colleague
    createColleagues();

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(checkGuest, 0, 0);
    gridLayout->addWidget(checkLogin, 0, 1);
    gridLayout->addWidget(new QLabel("Username:", this), 1, 0);
    gridLayout->addWidget(textUser, 1, 1);
    gridLayout->addWidget(new QLabel("Password:", this), 2, 0);
    gridLayout->addWidget(textPass, 2, 1);
    gridLayout->addWidget(buttonOk, 3, 0);
    gridLayout->addWidget(buttonCancel, 3, 1);

    setLayout(gridLayout);
}

LoginFrame::~LoginFrame() {}

// 生成各个Colleague。
void LoginFrame::createColleagues() {
    // 生成
    QButtonGroup* chk_group = new QButtonGroup(this);
    checkGuest = new ColleagueCheckbox("Guest", this);
    checkLogin = new ColleagueCheckbox("Login", this);
    chk_group->addButton(checkGuest);
    chk_group->addButton(checkLogin);

    textUser = new ColleagueTextField("", this);
    textPass = new ColleagueTextField("", this);
    textPass->setEchoMode(QLineEdit::Password);

    buttonOk = new ColleagueButton("OK", this);
    buttonCancel = new ColleagueButton("Cancel", this);

    // 设置Mediator
    checkGuest->setMediator(this);
    checkLogin->setMediator(this);
    textUser->setMediator(this);
    textPass->setMediator(this);
    buttonOk->setMediator(this);
    buttonCancel->setMediator(this);

    // 设置Listener
}

void LoginFrame::colleagueChanged() {
}
