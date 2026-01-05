#include "widget.h"

#include <QVBoxLayout>
#include <QStringList>
#include <QHeaderView>

Widget::Widget(QWidget* parent, const QVector<State>& states) 
    : QWidget(parent) {
    // 创建布局
    QVBoxLayout* layout = new QVBoxLayout(this);

    // 创建树形控件
    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(4);

    // 设置列标题
    QStringList headers;
    headers << "Name" << "Abbrev" << "Capital" << "Founded";
    treeWidget->setHeaderLabels(headers);

    // 设置列宽
    treeWidget->setColumnWidth(0, 100);
    treeWidget->setColumnWidth(1, 50);
    treeWidget->setColumnWidth(2, 100);
    treeWidget->setColumnWidth(3, 70);

    // 设置列不可拉伸
    QHeaderView* header = treeWidget->header();
    header->setSectionResizeMode(0, QHeaderView::Fixed);
    header->setSectionResizeMode(1, QHeaderView::Fixed);
    header->setSectionResizeMode(2, QHeaderView::Fixed);
    header->setSectionResizeMode(3, QHeaderView::Fixed);

    // 设置标题字体加粗
    QFont font = header->font();
    font.setBold(true);
    header->setFont(font);

    // 添加数据
    for (const State& state : states) {
        QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget);
        item->setText(0, state.getStateName());
        item->setText(1, state.getAbbrev());
        item->setText(2, state.getCapital());
        item->setText(3, state.getFounded());
    }

    // 将树形控件添加到布局
    layout->addWidget(treeWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    // 设置布局
    setLayout(layout);
}

