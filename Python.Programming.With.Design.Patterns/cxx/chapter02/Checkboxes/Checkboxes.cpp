#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QDebug>
#include <QList>

// 自定义复选框，继承自 QCheckBox（对应 tkinter 的 Checkbutton）
class Checkbox : public QCheckBox {
public:
    Checkbox(QWidget* parent, const QString& btext, int /* dummy for IntVar */)
        : QCheckBox(btext, parent), text(btext)
    {
        // 互联网梗：菠萝不能上披萨
        if (text == "Pineapple") {
            setEnabled(false);          // 禁用菠萝选项
        }
    }

    QString getText() const { return text; }
    int getVar() const { return isChecked() ? 1 : 0; }  // 模拟 IntVar.get()

private:
    QString text;
};

// 自定义按钮，继承自 QPushButton（对应 tkinter 的 Button）
class OKButton : public QPushButton {
public:
    OKButton(QWidget* parent, const QList<Checkbox*>& boxes)
        : QPushButton("Order", parent), boxes(boxes)
    {
        // 将按钮点击信号连接到自定义的 comd 方法（lambda 方式）
        connect(this, &QPushButton::clicked, this, [this]() { comd(); });
    }

    void comd() {
        for (Checkbox* box : boxes) {
            qDebug() << box->getText() << box->getVar();
        }
    }

private:
    QList<Checkbox*> boxes;
};

// 界面初始化类（与原 Python 类名、结构保持一致）
class InitUI {
public:
    InitUI(QWidget* root) {
        QStringList names = { "Cheese", "Pepperoni", "Mushrooms",
                              "Sausage", "Peppers", "Pineapple" };

        root->setWindowTitle("Pizza");
        root->setFixedSize(200, 175);            // 对应 geometry("200x175")

        QGridLayout* layout = new QGridLayout(root);
        QList<Checkbox*> boxes;
        int row = 0;

        for (const QString& name : names) {
            // 每个复选框独立，原 IntVar 参数用 0（占位）代替
            Checkbox* cb = new Checkbox(root, name, 0);
            boxes.append(cb);
            layout->addWidget(cb, row, 0, Qt::AlignLeft);  // sticky=W
            ++row;
        }

        // 创建 Order 按钮，传入复选框列表
        OKButton* btn = new OKButton(root, boxes);
        layout->addWidget(btn, 3, 1);            // column=1, row=3
        // 模拟 padx=20：设置第1列最小宽度为20
        layout->setColumnMinimumWidth(1, 20);
        layout->setAlignment(btn, Qt::AlignCenter);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget root;
    InitUI ui(&root);      // 创建界面（与原代码完全一致）
    root.show();
    return app.exec();     // 替代原来的 mainloop()
}