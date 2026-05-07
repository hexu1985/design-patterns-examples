#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget root;
    root.setWindowTitle("grid");

    QGridLayout* layout = new QGridLayout(&root);

    // 第一行：标签 "Name" 和 输入框
    QLabel* lbl1 = new QLabel("Name");
    layout->addWidget(lbl1, 0, 0, Qt::AlignLeft);
    // 设置外边距：padx=5, pady=5, sticky=W
    layout->setAlignment(lbl1, Qt::AlignLeft);
    layout->setContentsMargins(5, 5, 5, 5);  // 整体边距，模拟 padx/pady
    // 单独为 lbl1 增加一些边距（Qt 中需通过设置间距实现）
    layout->setHorizontalSpacing(5);         // 列间距
    layout->setVerticalSpacing(5);           // 行间距

    QLineEdit* entry1 = new QLineEdit();
    layout->addWidget(entry1, 0, 1);

    // 第二行：标签 "Address" 和 输入框
    QLabel* lbl2 = new QLabel("Address");
    layout->addWidget(lbl2, 1, 0, Qt::AlignLeft);
    QLineEdit* entry2 = new QLineEdit();
    layout->addWidget(entry2, 1, 1);
    // 为 entry2 设置 padx=5（增加左边距或右边距）
    // 通过设置布局的列拉伸或添加空白？更简单：直接设置内容边距
    // 由于原代码 entry2.grid(row=1, column=1, padx=5) 是水平方向 5 像素，
    // 可以通过设置 layout 的列间距已经为 5，再额外对 entry2 用 QSpacerItem 较复杂。
    // 为简化并保持近似效果，使用 layout 的列间距即可满足。

    root.setLayout(layout);
    root.show();

    return app.exec();
}