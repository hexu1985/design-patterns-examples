#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

// Dbutton 基类：禁用/启用按钮，并定义纯虚函数 comd()
class Dbutton : public QPushButton {
public:
    Dbutton(QWidget* master = nullptr, const QString& text = "")
        : QPushButton(text, master)
    {
        connect(this, &QPushButton::clicked, this, &Dbutton::onClicked);
    }

    virtual void comd() = 0;      // 纯虚函数，由子类实现

    void disable() {
        setEnabled(false);
    }

    void enable() {
        setEnabled(true);
    }

private slots:
    void onClicked() {
        comd();
    }
};

// 前向声明 Mediator
class Mediator;

// SampleButton：点击后通过 Mediator 启用 QuitButton
class SampleButton : public Dbutton {
public:
    SampleButton(QWidget* root, Mediator* med, const QString& text = "Sample")
        : Dbutton(root, text), med(med)
    {
        enable();                 // 初始启用
    }

    void comd() override;

private:
    Mediator* med;
};

// QuitButton：点击后退出程序，初始禁用
class QuitButton : public Dbutton {
public:
    QuitButton(QWidget* root, const QString& text = "Quit")
        : Dbutton(root, text)
    {
        disable();                // 初始禁用
    }

    void comd() override {
        QApplication::quit();
    }
};

// Mediator：协调两个按钮
class Mediator {
public:
    void setSbutton(SampleButton* sbutton) {
        this->sbutton = sbutton;
    }

    void setQuit(QuitButton* qbutton) {
        this->qbutton = qbutton;
    }

    void sclicked() {
        if (qbutton) {
            qbutton->enable();    // 启用 QuitButton
        }
    }

private:
    SampleButton* sbutton = nullptr;
    QuitButton* qbutton = nullptr;
};

// 实现 SampleButton::comd（需要 Mediator 完整定义）
void SampleButton::comd() {
    if (med) {
        med->sclicked();
    }
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget root;                         // 类似 tk.Tk()
    Mediator med;                         // 中介者对象

    SampleButton* btn = new SampleButton(&root, &med);
    QuitButton* quitbutton = new QuitButton(&root);

    med.setQuit(quitbutton);
    // med.setSbutton(btn);   // 原代码中未使用，但可保留

    // 网格布局，与原 grid(column, row) 一致
    QGridLayout* layout = new QGridLayout(&root);
    layout->addWidget(btn, 0, 0);
    layout->addWidget(quitbutton, 0, 1);
    root.setLayout(layout);

    root.show();
    return app.exec();                    // 主循环
}