#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QDebug>
#include <QList>

// Checkbox class derived from QCheckBox
// includes get methods to get the name and state
class Checkbox : public QCheckBox {
public:
    Checkbox(QWidget* parent, const QString& btext, int /* dummy for signature match */)
        : QCheckBox(btext, parent), text(btext)
    {
        // Internet joke about Pineapple on pizza
        if (text == "Pineapple") {
            setEnabled(false);          // prevent Pineapple on pizza
        }
    }

    QString getText() const { return text; }
    int getVar() const { return isChecked() ? 1 : 0; }

private:
    QString text;
};

// Button with comd method to print out list of toppings ordered
// keeps a reference to the list of checkboxes
class OKButton : public QPushButton {
    Q_OBJECT   // needed for custom slot
public:
    OKButton(QWidget* parent, const QList<Checkbox*>& boxes)
        : QPushButton("Order", parent), boxes(boxes)
    {
        connect(this, &QPushButton::clicked, this, &OKButton::comd);
    }

private slots:
    void comd() {
        for (Checkbox* box : boxes) {
            qDebug() << box->getText() << box->getVar();
        }
    }

private:
    QList<Checkbox*> boxes;
};

// Create the window, checkboxes and Order button
// Also creates a list containing the checkboxes
// and passes it to the Order button
class InitUI {
public:
    InitUI(QWidget* root) {
        QStringList names;
        names << "Cheese" << "Pepperoni" << "Mushrooms"
              << "Sausage" << "Peppers" << "Pineapple";

        root->setWindowTitle("Pizza");
        root->setFixedSize(200, 175);

        QGridLayout* layout = new QGridLayout(root);
        QList<Checkbox*> boxes;
        int row = 0;

        for (const QString& name : names) {
            // create an IntVar-like dummy (not needed in Qt, just pass 0)
            Checkbox* cb = new Checkbox(root, name, 0);
            boxes.append(cb);
            layout->addWidget(cb, row, 0, Qt::AlignLeft);
            ++row;
        }

        // Create the Order button and give it the list of boxes
        OKButton* okBtn = new OKButton(root, boxes);
        layout->addWidget(okBtn, 3, 1);    // column=1, row=3
        // add some padding like padx=20 in tkinter
        layout->setColumnMinimumWidth(1, 20);
        layout->setAlignment(okBtn, Qt::AlignCenter);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget root;
    InitUI ui(&root);
    root.show();
    return app.exec();
}

// Include moc-generated code when using Q_OBJECT in a .cpp file
#include "checkboxes.moc"
