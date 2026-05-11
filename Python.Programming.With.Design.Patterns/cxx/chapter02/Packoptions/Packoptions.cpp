#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 主窗口（对应 tk.Tk()）
    QWidget root;
    root.setWindowTitle("pack demo");
    root.resize(300, 100);  // 设置初始尺寸，类似 Tk 窗口默认大小

    // 垂直布局，容纳两个 frame（对应两个 Frame().pack(fill=X)）
    QVBoxLayout *mainLayout = new QVBoxLayout(&root);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // 第一个水平容器（对应 frame1）
    QWidget *frame1 = new QWidget(&root);
    QHBoxLayout *layout1 = new QHBoxLayout(frame1);
    layout1->setContentsMargins(5, 5, 5, 5);
    layout1->setSpacing(5);

    // 标签（对应 lbl1）
    QLabel *lbl1 = new QLabel("Name", frame1);
    lbl1->setFixedWidth(70);             // width=7（按字符数估算，7个英文字符宽度约70px）
    layout1->addWidget(lbl1, 0, Qt::AlignLeft);  // side=LEFT

    // 输入框（对应 entry1）
    QLineEdit *entry1 = new QLineEdit(frame1);
    layout1->addWidget(entry1, 1);       // stretch=1，模拟 expand=True
    // fill=X 通过设置 QHBoxLayout 中第二个控件可拉伸实现，且布局本身填满父窗口

    mainLayout->addWidget(frame1);       // frame1.pack(fill=X) → 水平方向填满

    // 第二个水平容器（对应 frame2）
    QWidget *frame2 = new QWidget(&root);
    QHBoxLayout *layout2 = new QHBoxLayout(frame2);
    layout2->setContentsMargins(5, 5, 5, 5);
    layout2->setSpacing(5);

    QLabel *lbl2 = new QLabel("Address", frame2);
    lbl2->setFixedWidth(70);
    layout2->addWidget(lbl2, 0, Qt::AlignLeft);

    QLineEdit *entry2 = new QLineEdit(frame2);
    layout2->addWidget(entry2, 1);

    mainLayout->addWidget(frame2);

    root.setLayout(mainLayout);
    root.show();

    return app.exec();  // 对应 root.mainloop()
}

