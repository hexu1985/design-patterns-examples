#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>

// ChoiceButton 继承自 QRadioButton，对应原 Python 的 Radiobutton
class ChoiceButton : public QRadioButton {
public:
    ChoiceButton(QWidget* parent, const QString& color, int index, QButtonGroup* /*gvar*/, QLabel* clabel)
        : QRadioButton(color, parent), clabel(clabel), color(color)
    {
        // 设置内边距（Qt 中用样式表模拟 padx=20）
        setStyleSheet("QRadioButton { padding-left: 20px; }");
        // 连接 clicked 信号到自定义槽
        connect(this, &QRadioButton::clicked, this, &ChoiceButton::comd);
    }

private slots:
    void comd() {
        // 改变标签文字和颜色
        clabel->setText(color);
        clabel->setStyleSheet(QString("QLabel { color: %1; }").arg(color));
    }

private:
    QLabel* clabel;
    QString color;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 主窗口
    QWidget root;
    root.setWindowTitle("Choose your favourite color");

    // 垂直布局（模拟 pack() 的自动排列）
    QVBoxLayout* layout = new QVBoxLayout(&root);

    // 提示标签
    QLabel* prompt = new QLabel("Choose your favourite color:", &root);
    prompt->setAlignment(Qt::AlignLeft);        // justify=LEFT
    prompt->setStyleSheet("QLabel { padding-left: 20px; }"); // padx=20
    layout->addWidget(prompt);

    // 创建按钮组（虽然 Qt 的 QRadioButton 自动互斥，但保留以模拟 IntVar）
    QButtonGroup* groupv = new QButtonGroup(&root);
    groupv->setExclusive(true);   // 确保互斥

    // 底部标签
    QLabel* cLabel = new QLabel("color", &root);
    // 不需要布局对齐，将在添加后设置

    // 创建三个单选按钮
    ChoiceButton* redBtn = new ChoiceButton(&root, "Red", 0, groupv, cLabel);
    ChoiceButton* blueBtn = new ChoiceButton(&root, "Blue", 1, groupv, cLabel);
    ChoiceButton* greenBtn = new ChoiceButton(&root, "Green", 2, groupv, cLabel);

    // 添加按钮到布局（原代码中每个按钮都调用了 pack()）
    layout->addWidget(redBtn);
    layout->addWidget(blueBtn);
    layout->addWidget(greenBtn);
    layout->addWidget(cLabel);

    // 初始无按钮被选中（对应 groupv.set(None)）
    // Qt 中默认无选中，无需额外设置
    // 但为了明确，可以取消所有选中
    if (groupv->checkedButton()) {
        groupv->checkedButton()->setAutoExclusive(false);
        groupv->checkedButton()->setChecked(false);
        groupv->checkedButton()->setAutoExclusive(true);
    }

    root.setLayout(layout);
    root.show();

    return app.exec();   // 对应 root.mainloop()
}