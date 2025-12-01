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

    // 创建输入框
    _entry = new QLineEdit(this);
    _entry->setPlaceholderText("Type to search...");

    // 连接键盘事件
    connect(_entry, &QLineEdit::textChanged, 
            this, &Widget::onKeyPress);

    // 添加到左侧布局
    leftLayout->addWidget(_listWidget);
    leftLayout->addWidget(_entry);

    // 创建右侧标签区域
    QWidget* rightWidget = new QWidget(this);
    QVBoxLayout* rightLayout = new QVBoxLayout(rightWidget);
    rightLayout->setAlignment(Qt::AlignTop);

    // 创建四个标签
    _lbState = new QLabel("", this);
    _lbAbbrev = new QLabel("", this);
    _lbCapital = new QLabel("", this);
    _lbFounded = new QLabel("", this);

    // 设置缩写标签为红色
    QPalette palette = _lbAbbrev->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    _lbAbbrev->setPalette(palette);

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

    // 设置输入框焦点
    _entry->setFocus();
}

void Widget::onSelectionChanged() {
    QList<QListWidgetItem*> selectedItems = _listWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int index = _listWidget->row(selectedItems.first());
        if (index >= 0 && index < _states.size()) {
            const State& state = _states[index];
            loadLabels(state);
        }
    }
}

void Widget::loadLabels(const State& state) {
    // 填充标签信息
    _lbState->setText(state.getStateName());
    _lbAbbrev->setText(state.getAbbrev());
    _lbCapital->setText(state.getCapital());
    _lbFounded->setText(state.getFounded());
}

void Widget::onKeyPress() {
    QString charStr = _entry->text().toUpper();
    if (charStr.isEmpty()) {
        return;
    }

    bool found = false;
    int i = 0;

    // 搜索以输入字符开头的州
    while (!found && i < _states.size()) {
        found = _states[i].getStateName().startsWith(charStr);
        if (!found) {
            i++;
        }
    }

    if (found) {
        const State& state = _states[i];

        // 清除当前选择
        _listWidget->clearSelection();

        // 设置新选择
        _listWidget->setCurrentRow(i);

        // 确保可见
        _listWidget->scrollToItem(_listWidget->item(i),
                QAbstractItemView::PositionAtTop);

        // 加载标签信息
        loadLabels(state);
    }
}
