// main.cpp
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QStringList>
#include <QVector>
#include <QDebug>

// Abstract base class that the listbox and checkbox choice widgets are derived from
class MultiChoice : public QWidget {
protected:
    QStringList choices;
    QWidget* container;

public:
    MultiChoice(QWidget* frame, const QStringList& choiceList) 
        : QWidget(frame), choices(choiceList), container(frame) {
    }

    virtual ~MultiChoice() {}

    // To be implemented in derived classes
    virtual void makeUI() = 0;  // Fill a widget with components
    virtual QStringList getSelected() = 0;  // Get list of items

    // Clears out the components of the container
    void clearAll() {
        // Remove all child widgets from container
        QList<QWidget*> children = container->findChildren<QWidget*>();
        for (QWidget* child : children) {
            if (child->parent() == container) {
                delete child;
            }
        }
        
        // Also delete the layout if exists
        if (container->layout()) {
            delete container->layout();
        }
    }
};

// Abstract button class with empty command function
class DButton : public QPushButton {
    Q_OBJECT

public:
    DButton(QWidget* master = nullptr, const QString& text = "")
        : QPushButton(text, master) {
        connect(this, &QPushButton::clicked, this, &DButton::comd);
    }

protected:
    // Abstract method to be called by children
    virtual void comd() = 0;
};

// Pops up message box showing selected securities
class ShowButton : public DButton {
    Q_OBJECT

private:
    class BuildUI* bldr;

public:
    ShowButton(class BuildUI* builder, QWidget* root)
        : DButton(root, "Show"), bldr(builder) {
    }

protected:
    void comd() override {
        QStringList list = bldr->getSelected();
        QString text;
        for (const QString& stock : list) {
            text += stock + "\n";
        }
        QMessageBox::information(nullptr, "Selected securities", text);
    }
};

// ListboxChoice class
class ListboxChoice : public MultiChoice {
private:
    QListWidget* list;

public:
    ListboxChoice(QWidget* frame, const QStringList& choices)
        : MultiChoice(frame, choices), list(nullptr) {
    }

    // Creates and loads the listbox into the frame
    void makeUI() override {
        clearAll();
        
        QVBoxLayout* layout = new QVBoxLayout(container);
        container->setLayout(layout);
        
        // Create a list box
        list = new QListWidget(container);
        list->setSelectionMode(QAbstractItemView::MultiSelection);
        layout->addWidget(list);
        
        // Add investments into list box
        for (const QString& st : choices) {
            list->addItem(st);
        }
    }
    
    // Returns a list of the selected elements
    QStringList getSelected() override {
        QStringList selist;
        QList<QListWidgetItem*> selected = list->selectedItems();
        for (QListWidgetItem* item : selected) {
            selist.append(item->text());
        }
        return selist;
    }
};

// Checkbox class derived from QCheckBox
class Checkbox : public QCheckBox {
private:
    QString text;

public:
    Checkbox(QWidget* root, const QString& btext)
        : QCheckBox(btext, root), text(btext) {
    }
    
    QString getText() const {
        return text;
    }
    
    // Returns whether checked or not
    bool isChecked() const {
        return QCheckBox::isChecked();
    }
};

// CheckboxChoice class
class CheckboxChoice : public MultiChoice {
private:
    QVector<Checkbox*> boxes;

public:
    CheckboxChoice(QWidget* panel, const QStringList& choices)
        : MultiChoice(panel, choices) {
    }
    
    // Creates the checkbox UI
    void makeUI() override {
        boxes.clear();
        clearAll();
        
        QGridLayout* layout = new QGridLayout(container);
        container->setLayout(layout);
        
        int r = 0;
        for (const QString& name : choices) {
            Checkbox* cb = new Checkbox(container, name);
            boxes.append(cb);
            layout->addWidget(cb, r, 0, Qt::AlignLeft);
            r++;
        }
    }
    
    // Returns list of selected check boxes
    QStringList getSelected() override {
        QStringList items;
        for (Checkbox* b : boxes) {
            if (b->isChecked()) {
                items.append(b->getText());
            }
        }
        return items;
    }
};

// Factory that makes either a ListboxChoice or CheckboxChoice
class ChoiceFactory {
public:
    // Returns a widget containing a set of choices displayed by one of several UI methods
    MultiChoice* getChoiceUI(const QStringList& choices, QWidget* frame) {
        if (choices.size() <= 3) {
            // Return a panel of checkboxes
            return new CheckboxChoice(frame, choices);
        } else {
            // Return a multi-select list box panel
            return new ListboxChoice(frame, choices);
        }
    }
};

// List of securities and name of type of security
class Securities {
private:
    QString name;
    QStringList list;

public:
    Securities(const QString& n, const QStringList& l)
        : name(n), list(l) {
    }
    
    QString getName() const {
        return name;
    }
    
    // Returns list of security names
    QStringList getList() const {
        return list;
    }
};

// UI Builder class creates window and securities lists
class BuildUI : public QObject {
    Q_OBJECT

private:
    QWidget* root;
    QVector<Securities*> seclist;
    QListWidget* leftList;
    QWidget* rframe;
    MultiChoice* cui;
    ShowButton* showbutton;

public:
    BuildUI(QWidget* rootWidget) 
        : QObject(rootWidget), root(rootWidget), leftList(nullptr), 
          rframe(nullptr), cui(nullptr), showbutton(nullptr) {
        root->resize(250, 200);
        root->setWindowTitle("Wealth Builder");
    }
    
    // Create the UI
    void build() {
        // Create securities list
        Securities* stocks = new Securities("Stocks", 
            QStringList() << "Cisco" << "Coca Cola" << "General Electric" 
                          << "Harley-Davidson" << "IBM");
        seclist.append(stocks);
        
        Securities* bonds = new Securities("Bonds", 
            QStringList() << "CT State GO 2024" << "New York GO 2026" << "GE Corp Bonds");
        seclist.append(bonds);
        
        Securities* mutuals = new Securities("Mutuals", 
            QStringList() << "Fidelity Magellan" << "T Rowe Price" 
                          << "Vanguard Primecap" << "Lindner");
        seclist.append(mutuals);
        
        // 使用QGridLayout保持grid布局
        QGridLayout* gridLayout = new QGridLayout(root);
        root->setLayout(gridLayout);
        
        // Fill left list box with security types (row=0, column=0)
        QWidget* lframe = new QWidget(root);
        lframe->setLayout(new QVBoxLayout());
        gridLayout->addWidget(lframe, 0, 0);
        
        // Create left listbox
        leftList = new QListWidget(lframe);
        leftList->setSelectionMode(QAbstractItemView::SingleSelection);
        lframe->layout()->addWidget(leftList);
        
        // Add in names of types of securities
        for (Securities* sec : seclist) {
            leftList->addItem(sec->getName());
        }
        
        // Connect select event
        connect(leftList, &QListWidget::itemSelectionChanged, 
                this, &BuildUI::lbselect);
        
        // Right frame (row=0, column=1)
        rframe = new QWidget(root);
        rframe->setObjectName("right");
        gridLayout->addWidget(rframe, 0, 1);
        
        // Show button (row=1, column=0, columnSpan=2)
        showbutton = new ShowButton(this, root);
        gridLayout->addWidget(showbutton, 1, 0, 1, 2);  // row=1, col=0, rowSpan=1, colSpan=2
    }
    
    // Callback when left list box is selected
    void lbselect() {
        QList<QListWidgetItem*> selected = leftList->selectedItems();
        if (selected.isEmpty()) return;
        
        int i = leftList->row(selected[0]);
        Securities* securities = seclist[i];
        
        ChoiceFactory cf;
        if (cui) {
            delete cui;
        }
        cui = cf.getChoiceUI(securities->getList(), rframe);
        cui->makeUI();  // Creates right hand panel
        
        // 将cui添加到rframe中
        QLayout* layout = rframe->layout();
        if (!layout) {
            layout = new QVBoxLayout(rframe);
            rframe->setLayout(layout);
        } else {
            // 清除之前的widget
            QLayoutItem* item;
            while ((item = layout->takeAt(0)) != nullptr) {
                if (item->widget())
                    item->widget()->deleteLater();
                delete item;
            }
        }
        layout->addWidget(cui);
    }
    
    // Returns list of selected items no matter what display
    QStringList getSelected() {
        if (cui) {
            return cui->getSelected();
        }
        return QStringList();
    }
};

// Main function
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    QWidget window;
    BuildUI builder(&window);
    builder.build();
    
    window.show();
    return app.exec();
}

// Include the moc file if needed (for Qt's meta-object system)
#include "BuildChoices.moc"