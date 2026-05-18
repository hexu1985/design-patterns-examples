#include "widget.h"

#include <QVBoxLayout>
#include <QListWidgetItem>

Widget::Widget(QWidget* parent, const QVector<State>& states) 
    : QWidget(parent), _states(states) {
    // 创建主水平布局
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    // 创建左侧列表和滚动条区域
    QWidget* leftWidget = new QWidget(this);
    QVBoxLayout* leftLayout = new QVBoxLayout(leftWidget);

    // 创建列表控件
    _listWidget = new QListWidget(this);
    _listWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // 添加州名到列表
    for (const State& state : _states) {
        _listWidget->addItem(state.getStateName());
    }

    // 连接选择信号
    connect(_listWidget, &QListWidget::itemSelectionChanged, 
            this, &Widget::onSelectionChanged);

    leftLayout->addWidget(_listWidget);

    // 创建右侧标签区域
    QWidget* rightWidget = new QWidget(this);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->setAlignment(Qt::AlignTop);

    // 创建三个标签
    _lbState = new QLabel("", this);
    _lbAbbrev = new QLabel("", this);
    _lbCapital = new QLabel("", this);

    // 设置缩写标签为红色
    QPalette palette = _lbAbbrev->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    _lbAbbrev->setPalette(palette);

    // 左对齐
    _lbState->setAlignment(Qt::AlignLeft);
    _lbAbbrev->setAlignment(Qt::AlignLeft);
    _lbCapital->setAlignment(Qt::AlignLeft);

    // 添加到右侧布局
    rightLayout->addWidget(_lbState);
    rightLayout->addWidget(_lbAbbrev);
    rightLayout->addWidget(_lbCapital);

    // 添加到主布局
    mainLayout->addWidget(leftWidget, 2);  // 左侧占更多空间
    mainLayout->addWidget(rightWidget, 1); // 右侧占较少空间

    // 设置布局边距
    mainLayout->setContentsMargins(10, 10, 10, 10);
    leftLayout->setContentsMargins(0, 0, 0, 0);
    rightLayout->setContentsMargins(10, 0, 0, 0);
}

void Widget::onSelectionChanged() {
    QList<QListWidgetItem*> selectedItems = _listWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int index = _listWidget->row(selectedItems.first());
        if (index >= 0 && index < _states.size()) {
            const State& state = _states[index];
            _lbState->setText(state.getStateName());
            _lbAbbrev->setText(state.getAbbrev());
            _lbCapital->setText(state.getCapital());
        }
    }
}
