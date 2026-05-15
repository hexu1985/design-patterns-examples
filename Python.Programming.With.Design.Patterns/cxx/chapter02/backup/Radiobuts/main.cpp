#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>

#include "ChoiceButton.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Color Choice Example");
    
    // 创建垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    
    // 创建说明标签
    QLabel *instructionLabel = new QLabel("Choose your favourite color:");
    instructionLabel->setAlignment(Qt::AlignLeft);
    instructionLabel->setStyleSheet("QLabel { margin-left: 20px; }"); // 类似于 padx=20
    
    // 创建显示选中颜色的标签
    QLabel *colorLabel = new QLabel("color");
    colorLabel->setAlignment(Qt::AlignCenter);
    
    // 创建按钮组来管理单选按钮
    QButtonGroup *buttonGroup = new QButtonGroup(&window);
    
    // 创建颜色选择按钮
    ChoiceButton *redButton = new ChoiceButton("Red", 0, buttonGroup, colorLabel);
    ChoiceButton *blueButton = new ChoiceButton("Blue", 1, buttonGroup, colorLabel);
    ChoiceButton *greenButton = new ChoiceButton("Green", 2, buttonGroup, colorLabel);
    
    // 将组件添加到布局
    mainLayout->addWidget(instructionLabel);
    mainLayout->addWidget(redButton);
    mainLayout->addWidget(blueButton);
    mainLayout->addWidget(greenButton);
    mainLayout->addWidget(colorLabel);
    
    // 设置初始状态：没有选中任何按钮
    // 在Qt中，默认就是没有选中的状态
    
    // 设置窗口大小并显示
    window.resize(300, 200);
    window.show();
    
    return app.exec();
}
