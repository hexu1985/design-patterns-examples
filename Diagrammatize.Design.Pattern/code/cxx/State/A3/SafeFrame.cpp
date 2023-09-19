#include "SafeFrame.hpp"
#include <sstream>
#include <iostream>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

#include "DayState.hpp"
#include "NightState.hpp"

SafeFrame::SafeFrame(QWidget *parent) : QWidget(parent) {
    state = DayState::getInstance();

    QVBoxLayout *mainLayout = new QVBoxLayout();

    textClock = new QLineEdit;
    textScreen = new QPlainTextEdit;

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonUse = new QPushButton("使用金库");
    buttonAlarm = new QPushButton("按下警铃");
    buttonPhone = new QPushButton("正常通话");
    buttonExit = new QPushButton("结束");
    buttonLayout->addWidget(buttonUse);
    buttonLayout->addWidget(buttonAlarm);
    buttonLayout->addWidget(buttonPhone);
    buttonLayout->addWidget(buttonExit);

    mainLayout->addWidget(textClock);
    mainLayout->addWidget(textScreen);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    QObject::connect(buttonExit, &QPushButton::clicked, &QApplication::quit);
    connect(buttonUse, SIGNAL(clicked()), this, SLOT(buttonUseClicked()));
    connect(buttonPhone, SIGNAL(clicked()), this, SLOT(buttonPhoneClicked()));
    connect(buttonAlarm, SIGNAL(clicked()), this, SLOT(buttonAlarmClicked()));
    connect(this, SIGNAL(signalSetClock(int)), this, SLOT(slotSetClock(int)));
}

SafeFrame::~SafeFrame() {
}

void SafeFrame::buttonUseClicked() {
    state->doUse(this);
}

void SafeFrame::buttonAlarmClicked() {
    state->doAlarm(this);
}

void SafeFrame::buttonPhoneClicked() {
    state->doPhone(this);
}

void SafeFrame::setClock(int hour) {
    emit signalSetClock(hour);
}

void SafeFrame::slotSetClock(int hour) {
    std::ostringstream os;
    os << "现在时间是";
    if (hour < 10) {
        os << "0" << hour << ":00";
    } else {
        os << hour << ":00";
    }
    std::string clockstring = os.str();
    std::cout << clockstring << std::endl;
    textClock->setText(QString::fromStdString(clockstring));
    state->doClock(this, hour);
}

void SafeFrame::changeState(State* state_) {
    std::cout << "从" << *state << "状態变为了" << *state_ << "状态。" << std::endl;
    state = state_;
}

void SafeFrame::callSecurityCenter(const std::string& msg) {
    std::ostringstream os;
    os << "call! " << msg; 
    textScreen->appendPlainText(QString::fromStdString(os.str()));
}

void SafeFrame::recordLog(const std::string& msg) {
    std::ostringstream os;
    os << "record ... " << msg; 
    textScreen->appendPlainText(QString::fromStdString(os.str()));
}
