#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStyleFactory>

// 基类 DButton，继承自 QPushButton，包含纯虚函数 comd()
class DButton : public QPushButton {
public:
    DButton(QWidget* master = nullptr, const QString& text = "")
        : QPushButton(text, master)
    {
        // 将按钮点击信号连接到 comd() 方法（使用 lambda）
        connect(this, &QPushButton::clicked, this, [this]() { comd(); });
    }

    // 抽象方法，由子类实现
    virtual void comd() = 0;
};

// OKButton 派生类，实现 comd() 显示消息框
class OKButton : public DButton {
public:
    OKButton(QWidget* root) : DButton(root, "OK") {
        // 设置左对齐并添加 10 像素外边距（模拟 pack(side=LEFT, padx=10)）
        // 具体布局由父窗口的 QHBoxLayout 管理
    }

    void comd() override {
        QMessageBox::information(nullptr, "our message", "tkinter is easy to use");
    }
};

// QuitButton 派生类，实现 comd() 退出程序
class QuitButton : public DButton {
public:
    QuitButton(QWidget* root) : DButton(root, "Quit") {
        // 设置红色文字（模拟 Style().configure("W.TButton", foreground="red")）
        this->setStyleSheet("QPushButton { color: red; }");
    }

    void comd() override {
        QApplication::quit();
    }
};

// 设置窗口和用户界面
void buildUI(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget root;                       // 对应 tkinter.Tk()
    root.setWindowTitle("pick one");
    root.setGeometry(300, 300, 200, 100);  // 原 geometry("200x100+300+300")

    // 使用水平布局管理两个按钮
    QHBoxLayout* layout = new QHBoxLayout(&root);
    layout->setContentsMargins(10, 0, 10, 0);  // 左右边距模拟 padx

    // 创建 OKButton
    OKButton* slogan = new OKButton(&root);
    layout->addWidget(slogan);
    layout->setAlignment(slogan, Qt::AlignLeft);  // side=LEFT

    // 创建 QuitButton
    QuitButton* button = new QuitButton(&root);
    layout->addWidget(button);
    layout->setAlignment(button, Qt::AlignRight); // side=RIGHT

    root.setLayout(layout);
    root.show();

    app.exec();
}

int main(int argc, char* argv[]) {
    buildUI(argc, argv);
}
