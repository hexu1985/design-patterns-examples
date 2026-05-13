#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Qt Layout Example");
    
    // 创建垂直布局作为主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    
    // 第一行 - 姓名
    QFrame *frame1 = new QFrame();
    QHBoxLayout *layout1 = new QHBoxLayout(frame1);
    layout1->setContentsMargins(0, 0, 0, 0); // 移除frame的边距
    
    QLabel *lbl1 = new QLabel("Name");
    lbl1->setFixedWidth(70); // 设置固定宽度，近似于Python中的width=7
    layout1->addWidget(lbl1);
    layout1->addSpacing(5); // padx=5
    
    QLineEdit *entry1 = new QLineEdit();
    layout1->addWidget(entry1);
    layout1->addSpacing(5); // padx=5
    
    // 设置entry1可以扩展填充剩余空间
    layout1->setStretchFactor(entry1, 1);
    
    // 第二行 - 地址
    QFrame *frame2 = new QFrame();
    QHBoxLayout *layout2 = new QHBoxLayout(frame2);
    layout2->setContentsMargins(0, 0, 0, 0); // 移除frame的边距
    
    QLabel *lbl2 = new QLabel("Address");
    lbl2->setFixedWidth(70); // 设置固定宽度
    layout2->addWidget(lbl2);
    layout2->addSpacing(5); // padx=5
    
    QLineEdit *entry2 = new QLineEdit();
    layout2->addWidget(entry2);
    layout2->addSpacing(5); // padx=5
    
    // 设置entry2可以扩展填充剩余空间
    layout2->setStretchFactor(entry2, 1);
    
    // 将两个frame添加到主布局
    mainLayout->addWidget(frame1);
    mainLayout->addWidget(frame2);
    
    // 设置主布局的边距来模拟pady=5
    mainLayout->setContentsMargins(0, 5, 0, 5);
    mainLayout->setSpacing(5); // 设置frame之间的间距
    
    window.show();
    
    return app.exec();
}
