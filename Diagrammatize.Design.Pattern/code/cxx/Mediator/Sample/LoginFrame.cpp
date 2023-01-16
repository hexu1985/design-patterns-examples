#include "LoginFrame.hpp"

#include <QGridLayout>
#include <QButtonGroup>

LoginFrame::LoginFrame(const std::string& title, QWidget *parent): QWidget(parent) {
    setWindowTitle(title.c_str());
    
    // 生成各个Colleague
    createColleagues();

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(checkGuest, 0, 0);
    gridLayout->addWidget(checkLogin, 0, 1);
    setLayout(gridLayout);
}

LoginFrame::~LoginFrame() {}

void LoginFrame::createColleagues() {
    QButtonGroup* chk_group = new QButtonGroup(this);
    checkGuest = new ColleagueCheckbox("Guest", this);
    checkLogin = new ColleagueCheckbox("Login", this);
    chk_group->addButton(checkGuest);
    chk_group->addButton(checkLogin);

}

void LoginFrame::colleagueChanged() {
}
