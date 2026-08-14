#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QStringList>
#include <QListWidgetItem>

// Forward declarations
class BuildUI;

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

// Derived QListWidget with 3 convenience methods
class DListbox : public QListWidget {
    Q_OBJECT

public:
    DListbox(QWidget* parent = nullptr) : QListWidget(parent) {}

    // Get the current selected text
    QString getSelected() {
        QListWidgetItem* item = currentItem();
        if (item) {
            return item->text();
        }
        return QString();
    }

    // Delete the selected row
    void deleteSelection() {
        int row = currentRow();
        if (row >= 0) {
            delete takeItem(row);
        }
    }

    // Insert at bottom of list
    void insertAtEnd(const QString& text) {
        addItem(text);
    }
};

class EntryButton : public DButton {
    Q_OBJECT

public:
    EntryButton(QWidget* parent, BuildUI* buildui) : DButton(parent), buildui(buildui) {
        setText("Enter");
    }

    // Copies entry field into left list
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

    // Copies selected line into right list
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
        resize(300, 200);
        setWindowTitle("Two lists");

        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        QGridLayout* layout = new QGridLayout(centralWidget);

        entry = new QLineEdit();
        layout->addWidget(entry, 0, 0);

        leftList = new DListbox();
        layout->addWidget(leftList, 1, 0, 4, 1);

        entryButton = new EntryButton(this, this);
        layout->addWidget(entryButton, 0, 1, Qt::AlignLeft);

        moveButton = new MoveButton(this, this);
        layout->addWidget(moveButton, 1, 1);

        rightList = new DListbox();
        layout->addWidget(rightList, 1, 2, 4, 1);

        restore = new RestoreButton(this, this);
        layout->addWidget(restore, 2, 1);

        // Set column stretch factors
        layout->setColumnStretch(0, 1);
        layout->setColumnStretch(2, 1);
    }

    DListbox* getRightList() {
        return rightList;
    }

    DListbox* getLeftList() {
        return leftList;
    }

    QLineEdit* getEntry() {
        return entry;
    }

private:
    QLineEdit* entry;
    DListbox* leftList;
    DListbox* rightList;
    EntryButton* entryButton;
    MoveButton* moveButton;
    RestoreButton* restore;
};

void EntryButton::comd() {
    QLineEdit* entry = buildui->getEntry();
    QString text = entry->text();
    DListbox* leftList = buildui->getLeftList();
    leftList->insertAtEnd(text);
    entry->clear(); // clears entry
}

void RestoreButton::comd() {
    DListbox* rlist = buildui->getRightList();
    QString seltext = rlist->getSelected();
    DListbox* leftlist = buildui->getLeftList();
    leftlist->insertAtEnd(seltext);
    rlist->deleteSelection();
}

void MoveButton::comd() {
    DListbox* leftlist = buildui->getLeftList();
    QString seltext = leftlist->getSelected();
    DListbox* rightlist = buildui->getRightList();
    rightlist->insertAtEnd(seltext);
    // And deletes from left
    leftlist->deleteSelection();
}

// Program starts here
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BuildUI bui;
    bui.show();
    return app.exec();
}

#include "addStudents.moc"
