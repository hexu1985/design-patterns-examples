#ifndef WIDGET_H
#define WIDGET_H

#include <vector>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    std::vector<QCheckBox*> boxes;
    QPushButton* ok_button;

private slots:
    void on_ok_button_clicked();
};

#endif // WIDGET_H
