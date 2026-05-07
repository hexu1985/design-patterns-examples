#include "widget.h"
#include "OKButton.hpp"
#include "Checkbox.hpp"

#include <QVBoxLayout>

Widget::Widget(QWidget* parent) : QWidget(parent) {
    // Initialize toppings list
    QStringList names = {"Cheese", "Pepperoni", "Mushrooms",
        "Sausage", "Peppers", "Pineapple"};

    setWindowTitle("Pizza");
    setFixedSize(200, 175);

    // Create layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Create checkboxes and add to layout
    for (const QString& name : names) {
        Checkbox* cb = new Checkbox(this, name);
        m_boxes.push_back(cb);
        mainLayout->addWidget(cb);
    }

    // Create the Order button and give it the list of boxes
    OKButton* okBtn = new OKButton(this, m_boxes);
    mainLayout->addWidget(okBtn);

//    setLayout(mainLayout);
}

Widget::~Widget()
{
}

