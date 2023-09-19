#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

#include "Context.hpp"
#include "State.hpp"

class SafeFrame: public QWidget, public Context
{
    Q_OBJECT

public:
    SafeFrame(QWidget *parent = 0);
    ~SafeFrame();

    void setClock(int hour) override;
    void changeState(State* state) override;
    void callSecurityCenter(const std::string& msg) override;
    void recordLog(const std::string& msg) override;

signals:
    void signalSetClock(int hour);

private slots:
    void buttonUseClicked();
    void buttonAlarmClicked();
    void buttonPhoneClicked();
    void slotSetClock(int hour);

private:
    QLineEdit* textClock;
    QPlainTextEdit* textScreen;
    QPushButton* buttonUse;
    QPushButton* buttonAlarm;
    QPushButton* buttonPhone;
    QPushButton* buttonExit;
    State* state;
};
