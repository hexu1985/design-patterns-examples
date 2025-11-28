#include "widget.h"

#include <QVBoxLayout>
#include <QListWidgetItem>

Widget::Widget(QWidget* parent, const QVector<State>& states) 
    : QWidget(parent), _states(states) {

    // 创建布局和列表控件
    QVBoxLayout* layout = new QVBoxLayout(this);
    _listWidget = new QListWidget(this);
    layout->addWidget(_listWidget);

    // 添加州名到列表
    for (const State& state : _states) {
        _listWidget->addItem(state.getStateName());
    }

    // 连接选择信号（可选，对应Python中的bind）
    // connect(_listWidget, &QListWidget::itemSelectionChanged, 
    //         this, &Widget::onSelectionChanged);
}
    
void Widget::onSelectionChanged() {
    // 处理选择变化的代码
    QList<QListWidgetItem*> selectedItems = _listWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        // 可以在这里添加选择处理逻辑
    }
}
