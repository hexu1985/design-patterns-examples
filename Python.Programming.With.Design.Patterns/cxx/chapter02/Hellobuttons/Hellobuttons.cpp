#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

// 显示 slogan 消息框
void disp_slogan() {
    QMessageBox::information(nullptr, "our message", "tkinter is easy to use");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口（类似 tk.Tk()）
    QWidget root;
    root.setWindowTitle("pick one");          // 原代码未设置标题，但为完整可加
    root.setGeometry(300, 300, 200, 100);    // 对应 geometry("200x100+300+300")

    // 水平布局（类似 pack(side=LEFT/RIGHT)）
    QHBoxLayout *layout = new QHBoxLayout(&root);
    layout->setContentsMargins(10, 0, 10, 0); // 左右边距 padx=10

    // 创建 Hello 按钮（红色文字）
    QPushButton *slogan = new QPushButton("Hello", &root);
    //slogan->setStyleSheet("QPushButton { color: red; }"); // 原代码 Hello 不是红色，但按要求只对 QUIT 设红色；这里为了示例，可取消此行注释。
    // 若不需要红色则注释掉
    QObject::connect(slogan, &QPushButton::clicked, disp_slogan);
    layout->addWidget(slogan, 0, Qt::AlignLeft);  // side=LEFT

    // 创建退出按钮，红色文字
    QPushButton *quitBtn = new QPushButton("QUIT", &root);
    quitBtn->setStyleSheet("QPushButton { color: red; }");
    QObject::connect(quitBtn, &QPushButton::clicked, &app, &QApplication::quit);
    layout->addWidget(quitBtn, 0, Qt::AlignRight); // side=RIGHT

    root.setLayout(layout);
    root.show();

    return app.exec();  // 主循环
}
