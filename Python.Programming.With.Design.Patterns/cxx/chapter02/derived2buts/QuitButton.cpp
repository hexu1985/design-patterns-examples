#include "QuitButton.hpp"
#include <QApplication>

QuitButton::QuitButton(QWidget *parent) : DButton(parent) {
    setText("Quit");

    setStyleSheet(
            "QPushButton { color: red; }"          // 默认状态
            "QPushButton:hover { color: black; }"     // 鼠标悬停
            );
}

void QuitButton::comd() {
    QApplication::quit();
}
