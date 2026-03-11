#include "widget.h"

#include <QVBoxLayout>
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>

Widget::Widget(QWidget* parent, const QVector<State>& states) 
    : QWidget(parent) {
    // 创建布局
    QVBoxLayout* layout = new QVBoxLayout(this);

    // 创建表格控件
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);
    //tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 设置列标题
    QStringList headers;
    headers << "Name" << "Abbrev" << "Capital" << "Founded";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 设置列宽
    tableWidget->setColumnWidth(0, 100);
    tableWidget->setColumnWidth(1, 50);
    tableWidget->setColumnWidth(2, 100);
    tableWidget->setColumnWidth(3, 70);

    // 设置列不可拉伸
    QHeaderView* header = tableWidget->horizontalHeader();
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
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(state.getStateName()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(state.getAbbrev()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(state.getCapital()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(state.getFounded()));
    }

    // 将表格控件添加到布局
    layout->addWidget(tableWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    // 设置布局
    setLayout(layout);
}
