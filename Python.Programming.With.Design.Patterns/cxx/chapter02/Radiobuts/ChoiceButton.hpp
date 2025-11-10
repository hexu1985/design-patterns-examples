#pragma once

#include <QRadioButton>
#include <QLabel>
#include <QString>
#include <QButtonGroup>

// ChoiceButton 继承自 QRadioButton
class ChoiceButton : public QRadioButton
{
    Q_OBJECT

public:
    ChoiceButton(const QString& color, int index, QButtonGroup* group, QLabel* clabel, QWidget* parent = nullptr);

private slots:
    void onClicked();

private:
    QString m_color;
    int m_index;
    QLabel* m_clabel;
};
