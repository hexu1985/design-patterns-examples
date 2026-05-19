#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QHeaderView>

void buildUI(QWidget* root) {
    root->setFixedSize(400, 200);          // root.geometry("400x200")

    QTreeWidget* tree = new QTreeWidget(root);
    // 设置列头（对应 tree["columns"]）
    QStringList headers;
    headers << "Name" << "Abbrev" << "Capital" << "Founded";
    tree->setHeaderLabels(headers);

    // 设置列宽及拉伸策略（stretch=NO）
    tree->setColumnWidth(0, 100);
    tree->setColumnWidth(1, 50);
    tree->setColumnWidth(2, 100);
    tree->setColumnWidth(3, 70);
    // 禁止列自动拉伸
    tree->header()->setSectionResizeMode(0, QHeaderView::Fixed);
    tree->header()->setSectionResizeMode(1, QHeaderView::Fixed);
    tree->header()->setSectionResizeMode(2, QHeaderView::Fixed);
    tree->header()->setSectionResizeMode(3, QHeaderView::Fixed);

    // 设置表头字体加粗（对应 style.configure("Treeview.Heading", font=(None,10,"bold"))）
    QFont headerFont = tree->header()->font();
    headerFont.setBold(true);
    headerFont.setPointSize(10);
    tree->header()->setFont(headerFont);

    // 插入顶级项 "California"
    QTreeWidgetItem* folderCa = new QTreeWidgetItem(tree);
    folderCa->setText(0, "California");
    folderCa->setText(1, "CA");
    folderCa->setText(2, "Sacramento");
    folderCa->setText(3, "1845");

    // 插入顶级项 "Kansas"
    QTreeWidgetItem* kansas = new QTreeWidgetItem(tree);
    kansas->setText(0, "Kansas");
    kansas->setText(1, "KS");
    kansas->setText(2, "Topeka");
    kansas->setText(3, "1845");

    // 为 California 添加子项
    QTreeWidgetItem* subItem = new QTreeWidgetItem(folderCa);
    subItem->setText(0, "");
    subItem->setText(1, "");
    subItem->setText(2, "pop=508,529");
    subItem->setText(3, "");

    // 布局：使 tree 填满顶部并水平拉伸（对应 pack(side=TOP, fill=X)）
    QVBoxLayout* layout = new QVBoxLayout(root);
    layout->addWidget(tree);
    layout->setContentsMargins(0, 0, 0, 0);
    root->setLayout(layout);
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget root;
    root.setWindowTitle("State List");     // root.title("State List")
    buildUI(&root);
    root.show();

    return app.exec();
}
