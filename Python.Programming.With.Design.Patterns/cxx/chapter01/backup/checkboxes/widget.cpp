#include "widget.h"
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Pizza");
    this->resize(200, 175);

    std::vector<QString> names; 
    names.push_back("Cheese");
    names.push_back("Pepperoni");
    names.push_back("Mushrooms");
    names.push_back("Sausage");
    names.push_back("Peppers");
    names.push_back("Pineapple");

    QButtonGroup* chk_group = new QButtonGroup(this);

    for (const auto& name : names) {
        QCheckBox* box = new QCheckBox(name, this);
        if (name == "Pineapple") {
            box->setEnabled(false);
        }
        boxes.push_back(box);
        chk_group->addButton(box);
    }

    chk_group->setExclusive(false);

    QGridLayout *gridLayout = new QGridLayout(this);
    for (int i = 0; i < boxes.size(); i++) {
        gridLayout->addWidget(boxes[i], i, 0);
    }

    ok_button = new QPushButton("Order", this);
    gridLayout->addWidget(ok_button, 3, 1, 2, 1);

    connect(ok_button, SIGNAL(clicked()), this, SLOT(on_ok_button_clicked()));

    setLayout(gridLayout);
}

void Widget::on_ok_button_clicked()
{
    for (auto box : boxes) {
        qDebug() << box->text() << " " << box->isChecked();
    }
}

Widget::~Widget()
{

}
