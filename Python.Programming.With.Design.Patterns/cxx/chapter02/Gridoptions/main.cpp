#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 创建主窗口
    QWidget *window = new QWidget;
    window->setWindowTitle("grid");
    
    // 创建网格布局
    QGridLayout *gridLayout = new QGridLayout(window);
    
    // 创建标签和输入框
    QLabel *lbl1 = new QLabel("Name");
    QLineEdit *entry1 = new QLineEdit;
    
    QLabel *lbl2 = new QLabel("Address");
    QLineEdit *entry2 = new QLineEdit;
    
    // 添加控件到网格布局，设置边距和对齐方式
    // 第一行：Name标签和输入框
    gridLayout->addWidget(lbl1, 0, 0);  // 行0，列0
    gridLayout->addWidget(entry1, 0, 1); // 行0，列1
    
    // 设置第一行标签的左对齐和边距
    gridLayout->setAlignment(lbl1, Qt::AlignLeft);
    gridLayout->setContentsMargins(5, 5, 5, 5); // 左, 上, 右, 下
    
    // 第二行：Address标签和输入框
    gridLayout->addWidget(lbl2, 1, 0);  // 行1，列0
    gridLayout->addWidget(entry2, 1, 1); // 行1，列1
    
    // 设置第二行标签的左对齐
    gridLayout->setAlignment(lbl2, Qt::AlignLeft);
    
    // 设置列的最小宽度，模拟tkinter的布局效果
    gridLayout->setColumnMinimumWidth(0, 70); // 模拟width=7的效果
    
    // 显示窗口
    window->show();
    
    return app.exec();
}