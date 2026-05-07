#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 设置应用程序样式（类似于tkinter的alt主题）
    app.setStyle(QStyleFactory::create("Fusion"));
    
    // 创建主窗口
    QWidget *window = new QWidget;
    window->setWindowTitle("Qt Application");
    window->setFixedSize(100, 250);
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(window);
    mainLayout->setContentsMargins(10, 10, 10, 10); // 添加边距，类似于pady=5
    
    // 创建GroupBox（类似于LabelFrame）
    QGroupBox *groupBox = new QGroupBox("State data");
    // 使用样式表设置边框宽度和凸起效果
    groupBox->setStyleSheet("QGroupBox { "
                           "border: 7px outset gray; "
                           "margin-top: 1ex; "
                           "} "
                           "QGroupBox::title { "
                           "subcontrol-origin: margin; "
                           "padding: 0 5px; "
                           "}");
    
    // 创建GroupBox的布局并添加标签
    QVBoxLayout *groupLayout = new QVBoxLayout(groupBox);
    groupLayout->addWidget(new QLabel("State"));
    groupLayout->addWidget(new QLabel("Abbrev"));
    groupLayout->addWidget(new QLabel("Capital"));
    groupLayout->addWidget(new QLabel("Founded"));
    
    // 将GroupBox添加到主布局
    mainLayout->addWidget(groupBox);
    
    // 显示窗口
    window->show();
    
    return app.exec();
}