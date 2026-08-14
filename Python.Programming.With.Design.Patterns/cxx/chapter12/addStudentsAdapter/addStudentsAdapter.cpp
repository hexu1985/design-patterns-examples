#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QStringList>
#include <QRandomGenerator>
#include <QHeaderView>

// Forward declarations
class BuildUI;

// Random number generator
class Randint {
public:
    Randint() {
        // Qt's QRandomGenerator is automatically seeded
    }

    // Compute a random IQ between 115 and 145
    static int getIQ() {
        return QRandomGenerator::global()->bounded(115, 146); // 146 is exclusive
    }

    // Compute a random score between 25 and 35
    static int getScore() {
        return QRandomGenerator::global()->bounded(25, 36); // 36 is exclusive
    }
};

// Derived class from QPushButton that contains empty comd function
class DButton : public QPushButton {
    Q_OBJECT

public:
    DButton(QWidget* parent = nullptr) : QPushButton(parent) {
        connect(this, &QPushButton::clicked, this, &DButton::comd);
    }

    // Abstract method to be called by children
    virtual void comd() = 0;
};

class DListboxInterface {
public:
    virtual ~DListboxInterface() = default;

    // Get the current selected text
    virtual QString getSelected() = 0;

    // Delete the selected row
    virtual void deleteSelection() = 0;

    // Insert at bottom of list
    virtual void insertAtEnd(const QString& text) = 0; 
};

// 在类定义后添加
Q_DECLARE_INTERFACE(DListboxInterface, "com.example.DListboxInterface")

// Derived QListWidget with 3 convenience methods
class DListbox : public QListWidget, public DListboxInterface {
    Q_OBJECT

public:
    DListbox(QWidget* parent = nullptr) : QListWidget(parent) {}

    // Get the current selected text
    QString getSelected() override {
        QListWidgetItem* item = currentItem();
        if (item) {
            return item->text();
        }
        return QString();
    }

    // Delete the selected row
    void deleteSelection() override {
        int row = currentRow();
        if (row >= 0) {
            delete takeItem(row);
        }
    }

    // Insert at bottom of list
    void insertAtEnd(const QString& text) override {
        addItem(text);
    }
};

// Adapter class that works with QTreeWidget
class ListboxAdapter : public QObject, public DListboxInterface {
    Q_OBJECT

public:
    ListboxAdapter(QWidget* parent, QTreeWidget* tree) : QObject(parent), tree(tree) {
        index = 0;
    }

    // Gets the text selected from the tree
    QString getSelected() override {
        QTreeWidgetItem* item = tree->currentItem();
        if (item) {
            return item->text(0); // Get the text from column 0
        }
        return QString();
    }

    // Delete the line selected in the tree
    void deleteSelection() override {
        QTreeWidgetItem* item = tree->currentItem();
        if (item) {
            delete item;
        }
    }

    // Insert a line at the bottom of the treelist
    void insertAtEnd(const QString& name) override {
        // Create random IQs and scores
        QTreeWidgetItem* item = new QTreeWidgetItem(tree);
        item->setText(0, name);
        item->setText(1, QString::number(Randint::getIQ()));
        item->setText(2, QString::number(Randint::getScore()));
        index++;
    }

private:
    QTreeWidget* tree;
    int index;
};

class EntryButton : public DButton {
    Q_OBJECT

public:
    EntryButton(QWidget* parent, BuildUI* buildui) : DButton(parent), buildui(buildui) {
        setText("Enter");
    }

    void comd() override;

private:
    BuildUI* buildui;
};

class RestoreButton : public DButton {
    Q_OBJECT

public:
    RestoreButton(QWidget* parent, BuildUI* buildui) : DButton(parent), buildui(buildui) {
        setText("<--Restore");
    }

    void comd() override; 

private:
    BuildUI* buildui;
};

class MoveButton : public DButton {
    Q_OBJECT

public:
    MoveButton(QWidget* parent, BuildUI* buildui) : DButton(parent), buildui(buildui) {
        setText("Move-->");
    }

    void comd() override; 

private:
    BuildUI* buildui;
};

class BuildUI : public QMainWindow {
    Q_OBJECT

public:
    BuildUI(QWidget* parent = nullptr) : QMainWindow(parent) {
        build();
    }

    void build() {
        resize(400, 200);
        setWindowTitle("Two lists");

        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        QGridLayout* layout = new QGridLayout(centralWidget);

        // Entry field
        entry = new QLineEdit();
        layout->addWidget(entry, 0, 0);

        // Left list
        leftList = new DListbox();
        layout->addWidget(leftList, 1, 0, 4, 1);

        // Entry button
        entryButton = new EntryButton(this, this);
        layout->addWidget(entryButton, 0, 1, Qt::AlignLeft);

        // Move button
        moveButton = new MoveButton(this, this);
        layout->addWidget(moveButton, 1, 1);

        // Tree widget (right side)
        tree = new QTreeWidget();
        tree->setColumnCount(3);
        
        // Set up tree columns
        QStringList headers;
        headers << "Name" << "IQ" << "Score";
        tree->setHeaderLabels(headers);
        
        // Set column widths
        tree->setColumnWidth(0, 100);
        tree->setColumnWidth(1, 50);
        tree->setColumnWidth(2, 50);
        
        // Configure header
        tree->header()->setStretchLastSection(false);
        tree->header()->setSectionResizeMode(0, QHeaderView::Fixed);
        tree->header()->setSectionResizeMode(1, QHeaderView::Fixed);
        tree->header()->setSectionResizeMode(2, QHeaderView::Fixed);
        
        layout->addWidget(tree, 1, 2, 4, 1);

        // Create adapter for tree
        rightList = new ListboxAdapter(this, tree);

        // Restore button
        restore = new RestoreButton(this, this);
        layout->addWidget(restore, 2, 1);

        // Set column stretch factors
        layout->setColumnStretch(0, 1);
        layout->setColumnStretch(2, 1);
    }

    DListboxInterface* getRightList() {
        return rightList;
    }

    DListboxInterface* getLeftList() {
        return leftList;
    }

    QLineEdit* getEntry() {
        return entry;
    }

private:
    QLineEdit* entry;
    DListbox* leftList;
    ListboxAdapter* rightList;
    QTreeWidget* tree;
    EntryButton* entryButton;
    MoveButton* moveButton;
    RestoreButton* restore;
};

void EntryButton::comd() {
    QLineEdit* entry = buildui->getEntry();
    QString text = entry->text();
    DListboxInterface* leftList = buildui->getLeftList();
    leftList->insertAtEnd(text);
    entry->clear(); // clears entry
}

void RestoreButton::comd() {
    DListboxInterface* rlist = buildui->getRightList();
    QString seltext = rlist->getSelected();
    DListboxInterface* leftlist = buildui->getLeftList();
    leftlist->insertAtEnd(seltext);
    rlist->deleteSelection();
}

void MoveButton::comd() {
    DListboxInterface* leftlist = buildui->getLeftList();
    QString seltext = leftlist->getSelected();
    DListboxInterface* rightlist = buildui->getRightList();
    rightlist->insertAtEnd(seltext);
    leftlist->deleteSelection();
}

// Program starts here
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BuildUI bui;
    bui.show();
    return app.exec();
}

#include "addStudentsAdapter.moc"
