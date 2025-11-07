#include "widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent) : QWidget(parent) {
    setFixedSize(350, 200);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 10, 20, 10);

    // Top label
    QLabel *titleLabel = new QLabel("Enter numbers to add", this);
    titleLabel->setStyleSheet("color: blue;");
    titleLabel->setAlignment(Qt::AlignLeft);
    mainLayout->addWidget(titleLabel);

    // x entry field
    QHBoxLayout *xLayout = new QHBoxLayout();
    QLabel *xLabel = new QLabel("x=", this);
    xLabel->setStyleSheet("color: blue;");
    xEntry = new QLineEdit(this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xEntry);
    mainLayout->addLayout(xLayout);

    // y entry field
    QHBoxLayout *yLayout = new QHBoxLayout();
    QLabel *yLabel = new QLabel("y=", this);
    yLabel->setStyleSheet("color: blue;");
    yEntry = new QLineEdit(this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yEntry);
    mainLayout->addLayout(yLayout);

    // OK button
    okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &Widget::getSum);
    mainLayout->addWidget(okButton, 0, Qt::AlignCenter);

    // Result label
    cLabel = new QLabel("sum", this);
    cLabel->setStyleSheet("color: blue;");
    cLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(cLabel);

    mainLayout->addStretch();
}

void Widget::getSum() {
    bool ok1, ok2;
    float xval = xEntry->text().toFloat(&ok1);
    float yval = yEntry->text().toFloat(&ok2);

    if (ok1 && ok2) {
        cLabel->setText(QString("Sum = %1").arg(xval + yval));
    } else {
        QMessageBox::critical(this, "Conversion error", "Not numbers");
    }
}
