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

    // 设置初始的启用起用/禁用状态
    colleagueChanged();
}

LoginFrame::~LoginFrame() {}

// 生成各个Colleague。
void LoginFrame::createColleagues() {
    // 生成
    QButtonGroup* chk_group = new QButtonGroup(this);
    checkGuest = new ColleagueCheckbox("Guest", this);
    checkGuest->setChecked(true);
    checkLogin = new ColleagueCheckbox("Login", this);
    checkLogin->setChecked(false);

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
    connect(checkGuest, SIGNAL(toggled(bool)), checkGuest, SLOT(itemStateChanged(bool)));
    connect(checkLogin, SIGNAL(toggled(bool)), checkLogin, SLOT(itemStateChanged(bool)));
    connect(textUser,  SIGNAL(textChanged(const QString &)), textUser, SLOT(textValueChanged(const QString &)));
    connect(textPass,  SIGNAL(textChanged(const QString &)), textPass, SLOT(textValueChanged(const QString &)));
    connect(buttonOk, SIGNAL(clicked()), this, SLOT(actionPerformed()));
    connect(buttonCancel, SIGNAL(clicked()), this, SLOT(actionPerformed()));
}

// 接收来自于Colleage的通知然后判断各Colleage的启用/禁用状态。
void LoginFrame::colleagueChanged() {
    if (checkGuest->isChecked()) {
        textUser->setColleagueEnabled(false);
        textPass->setColleagueEnabled(false);
        buttonOk->setColleagueEnabled(true);
    } else { // Login mode
        textUser->setColleagueEnabled(true);
        userpassChanged();
    }
}

// 当textUser或是textPass文本输入框中的文字发生变化时
// 判断各Colleage的启用/禁用状态
void LoginFrame::userpassChanged() {
    if (textUser->text().length() > 0) {
        textPass->setColleagueEnabled(true);
        if (textPass->text().length() > 0) {
            buttonOk->setColleagueEnabled(true);
        } else {
            buttonOk->setColleagueEnabled(false);
        }
    } else {
        textPass->setColleagueEnabled(false);
        buttonOk->setColleagueEnabled(false);
    }
}

void LoginFrame::actionPerformed() {
    close();
}
