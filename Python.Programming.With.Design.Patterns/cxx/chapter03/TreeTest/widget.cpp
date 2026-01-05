#include "widget.h"
#include <QVBoxLayout>
#include <QHeaderView>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    setWindowTitle("State List");
    resize(400, 200);

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 创建树形控件
    treeWidget = new QTreeWidget();
    layout->addWidget(treeWidget);

    // 设置列
    QStringList headers;
    headers << "Name" << "Abbrev" << "Capital" << "Founded";
    treeWidget->setHeaderLabels(headers);

    // 设置列宽
    treeWidget->setColumnWidth(0, 100);
    treeWidget->setColumnWidth(1, 50);
    treeWidget->setColumnWidth(2, 100);
    treeWidget->setColumnWidth(3, 70);

    // 设置列宽策略（不拉伸）
    treeWidget->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    treeWidget->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    treeWidget->header()->setSectionResizeMode(2, QHeaderView::Fixed);
    treeWidget->header()->setSectionResizeMode(3, QHeaderView::Fixed);

    // 设置表头字体加粗
    QFont headerFont = treeWidget->header()->font();
    headerFont.setBold(true);
    headerFont.setPointSize(10);
    treeWidget->header()->setFont(headerFont);

    // 添加数据
    // California 项
    QTreeWidgetItem *californiaItem = new QTreeWidgetItem(treeWidget);
    californiaItem->setText(0, "California");
    californiaItem->setText(1, "CA");
    californiaItem->setText(2, "Sacramento");
    californiaItem->setText(3, "1845");

    // Kansas 项
    QTreeWidgetItem *kansasItem = new QTreeWidgetItem(treeWidget);
    kansasItem->setText(0, "Kansas");
    kansasItem->setText(1, "KS");
    kansasItem->setText(2, "Topeka");
    kansasItem->setText(3, "1845");

    // California 的子项
    QTreeWidgetItem *californiaChild = new QTreeWidgetItem(californiaItem);
    californiaChild->setText(1, " ");
    californiaChild->setText(2, "pop=508,529");

    // 展开所有项以便查看
    treeWidget->expandAll();
}

