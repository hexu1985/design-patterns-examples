#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(const QString& color, int index, QButtonGroup* group, QLabel* clabel, QWidget* parent)
    : QRadioButton(color, parent), m_color(color), m_index(index), m_clabel(clabel)
{
    // 设置边距，类似于 padx=20
    setStyleSheet("QRadioButton { margin-left: 20px; }");

    // 添加到按钮组
    group->addButton(this, index);

    // 连接信号槽
    connect(this, &QRadioButton::clicked, this, &ChoiceButton::onClicked);
}

void ChoiceButton::onClicked()
{
    // 改变标签的文本和颜色
    m_clabel->setText(m_color);

    // 设置文本颜色
    QPalette palette = m_clabel->palette();
    palette.setColor(QPalette::WindowText, m_color);
    m_clabel->setPalette(palette);
}
