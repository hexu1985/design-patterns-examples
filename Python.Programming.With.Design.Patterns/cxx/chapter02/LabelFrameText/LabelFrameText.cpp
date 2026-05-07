#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 设置 Qt 应用程序样式，模拟 tkinter.ttk.Style().theme_use('alt')
    // Qt 中没有完全相同的主题，使用 'fusion' 或 'windows' 可近似，也可自定义样式表
    app.setStyle(QStyleFactory::create("fusion"));   // 或 "windows"

    QWidget root;
    root.setWindowTitle("State data");            // 原代码未显式设置标题，但可对应
    root.setFixedSize(100, 250);                  // geometry("100x250")

    // 创建 Labelframe 对应的 QGroupBox，设置边框宽度和 relief（凸起效果）
    QGroupBox *labelframe = new QGroupBox("State data", &root);
    labelframe->setFlat(false);                   // 保证边框显示
    // 通过样式表设置边框宽度为 7，样式为 raised（类似 RAISED）
    labelframe->setStyleSheet(
        "QGroupBox { border: 7px solid; border-radius: 0px; margin-top: 0.5em; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 3px 0 3px; }"
    );
    // 或者更直接地模拟 tkinter 的 RAISED 效果（使用边框样式）
    labelframe->setStyleSheet(
        "QGroupBox { border: 7px ridge palette(mid); margin-top: 1ex; }"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; }"
    );

    // 垂直布局，容纳四个标签（对应 pack()）
    QVBoxLayout *layout = new QVBoxLayout(labelframe);
    layout->setSpacing(5);            // 类似默认间距
    layout->setContentsMargins(0, 0, 0, 0);

    // 添加四个标签
    QLabel *label1 = new QLabel("State", labelframe);
    QLabel *label2 = new QLabel("Abbrev", labelframe);
    QLabel *label3 = new QLabel("Capital", labelframe);
    QLabel *label4 = new QLabel("Founded", labelframe);

    layout->addWidget(label1);
    layout->addWidget(label2);
    layout->addWidget(label3);
    layout->addWidget(label4);

    labelframe->setLayout(layout);

    // 将 QGroupBox 放入主窗口的中心布局
    QVBoxLayout *mainLayout = new QVBoxLayout(&root);
    mainLayout->addWidget(labelframe);
    mainLayout->setAlignment(labelframe, Qt::AlignCenter);
    root.setLayout(mainLayout);

    // 设置窗口边距模拟 pady=5（原代码 labelframe.pack(pady=5)）
    mainLayout->setContentsMargins(5, 5, 5, 5);   // 上下左右边距，下方多加一些

    root.show();
    return app.exec();            // 对应 mainloop()
}