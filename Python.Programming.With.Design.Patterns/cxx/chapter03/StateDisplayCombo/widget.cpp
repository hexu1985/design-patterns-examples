#include "widget.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QScrollBar>
#include <QListWidgetItem>

Widget::Widget(QWidget* parent, const QVector<State>& states) 
    : QWidget(parent), _states(states) {
    // 创建主水平布局
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // 创建左侧列表和滚动条区域
    QWidget* leftWidget = new QWidget(this);
    QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);

    // 创建左侧组合框
    _comboBox = new QComboBox(this);
    _comboBox->setCurrentIndex(0);

    // 添加州名到列表
    for (const State& state : _states) {
        _comboBox->addItem(state.getStateName());
    }

    // 连接选择信号
    connect(_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &Widget::onStateSelected);

    // 添加到左侧布局
    leftLayout->addWidget(_comboBox);

    // 创建右侧标签区域
    QWidget* rightWidget = new QWidget(this);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->setAlignment(Qt::AlignTop);

    // 创建四个标签
    _lbState = new QLabel("", this);
    _lbAbbrev = new QLabel("", this);
    _lbAbbrev->setStyleSheet("color: red;");
    _lbCapital = new QLabel("", this);
    _lbFounded = new QLabel("", this);

    // 左对齐
    _lbState->setAlignment(Qt::AlignLeft);
    _lbAbbrev->setAlignment(Qt::AlignLeft);
    _lbCapital->setAlignment(Qt::AlignLeft);
    _lbFounded->setAlignment(Qt::AlignLeft);

    // 添加到右侧布局
    rightLayout->addWidget(_lbState);
    rightLayout->addWidget(_lbAbbrev);
    rightLayout->addWidget(_lbCapital);
    rightLayout->addWidget(_lbFounded);

    // 添加到主布局
    mainLayout->addWidget(leftWidget, 2);  // 左侧占更多空间
    mainLayout->addWidget(rightWidget, 1); // 右侧占较少空间

    // 设置布局边距
    mainLayout->setContentsMargins(10, 10, 10, 10);
    leftLayout->setContentsMargins(0, 0, 0, 0);
    rightLayout->setContentsMargins(10, 0, 0, 0);

    // 设置窗口属性
    setWindowTitle("State List");
    setFixedSize(400, 200);
}

void Widget::onStateSelected(int index) {
    if (index >= 0 && index < _states.size()) {
        const State& state = _states[index];
        loadLabels(state);
    }
}

void Widget::loadLabels(const State& state) {
    // 填充标签信息
    _lbState->setText(state.getStateName());
    _lbAbbrev->setText(state.getAbbrev());
    _lbCapital->setText(state.getCapital());
    _lbFounded->setText(state.getFounded());
}

