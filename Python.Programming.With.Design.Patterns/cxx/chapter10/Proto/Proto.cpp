#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QDir>
#include <QVector>
#include <algorithm>

// Forward declarations
class BuildUI;

// Swimmer object holds all data on one swimmer
class Swimmer {
public:
    Swimmer(const QString& dataline) {
        QStringList sarray = dataline.split(",");
        QString names = sarray[0];
        QStringList narray = names.split(" ");
        frname = narray[0];
        lname = narray[1];
        age = sarray[1].toInt();
        club = sarray[2];
        seedtime = sarray[3];
        sex = sarray[4].trimmed();
        time = 0.0;

        // remove colon from times of 1 minute or greater
        // so they can be sorted numerically
        if (seedtime.contains(":")) {
            QStringList mins = seedtime.split(":");
            QString atime = mins[0] + mins[1]; // time with colon removed
            time = atime.toDouble(); // converted to float for sorting
        } else {
            time = seedtime.toDouble();
        }
    }

    // Concatenate first and last names
    QString getName() const {
        return frname + " " + lname;
    }

    QString frname;
    QString lname;
    int age;
    QString club;
    QString seedtime;
    QString sex;
    double time;
};

// Derived class from QPushButton that contains empty comd function
class DButton : public QPushButton {
    Q_OBJECT

public:
    DButton(QWidget* parent = nullptr) : QPushButton(parent) {
        connect(this, &QPushButton::clicked, this, &DButton::comd);
    }

private slots:
    // Abstract method to be called by children
    virtual void comd() = 0;
};

class ReloadButton : public DButton {
    Q_OBJECT

public:
    ReloadButton(QWidget* parent, BuildUI* bldr) : DButton(parent), bldr(bldr) {
        setText("Reload");
    }

    void comd() override; 

private:
    BuildUI* bldr;
};

class CopyButton : public DButton {
    Q_OBJECT

public:
    CopyButton(QWidget* parent, BuildUI* bldr) : DButton(parent), bldr(bldr) {
        setText("Copy");
    }

    void comd() override; 

private:
    BuildUI* bldr;
};

class CloneButton : public DButton {
    Q_OBJECT

public:
    CloneButton(QWidget* parent, BuildUI* bldr) : DButton(parent), bldr(bldr) {
        setText("Clone");
    }

    void comd() override; 

private:
    BuildUI* bldr;
};

class RefreshButton : public DButton {
    Q_OBJECT

public:
    RefreshButton(QWidget* parent, BuildUI* bldr) : DButton(parent), bldr(bldr) {
        setText("<--Refresh");
    }

    void comd() override; 

private:
    BuildUI* bldr;
};

class BuildUI : public QMainWindow {
    Q_OBJECT

public:
    BuildUI(QWidget* parent = nullptr) : QMainWindow(parent) {
        resize(400, 200);
        setWindowTitle("Prototype demo");
        
        readFile();
        swmrs = sortUpwards();

        // Build UI
        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        QGridLayout* layout = new QGridLayout(centralWidget);
        
        leftList = new QListWidget();
        leftList->setMaximumWidth(200);
        layout->addWidget(leftList, 0, 0, 4, 1);
        
        cloneButton = new CloneButton(this, this);
        layout->addWidget(cloneButton, 1, 1);
        
        copyButton = new CopyButton(this, this);
        layout->addWidget(copyButton, 2, 1);
        
        refreshButton = new RefreshButton(this, this);
        layout->addWidget(refreshButton, 3, 1);
        
        reloadButton = new ReloadButton(this, this);
        layout->addWidget(reloadButton, 4, 1);
        
        rightList = new QListWidget();
        rightList->setMaximumWidth(200);
        layout->addWidget(rightList, 0, 2, 4, 1);
        
        layout->setColumnStretch(0, 1);
        layout->setColumnStretch(2, 1);
        
        fillList(leftList, swmrs);
    }

    void readFile() {
        swimmers.clear();
        
        // Read in the data file for this event
        QString datafile = QDir::currentPath() + "/Swimmers.txt";
        QFile file(datafile);
        
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Cannot open file: " + datafile);
            return;
        }
        
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString swstring = in.readLine();
            if (!swstring.isEmpty()) {
                swimmers.append(Swimmer(swstring));
            }
        }
        file.close();
    }

    void reloadLeft() {
        readFile();
        swmrs = sortUpwards();
        fillList(leftList, swmrs);
    }

    void fillList(QListWidget* list, const QVector<Swimmer>& swmrs) {
        list->clear();
        for (const Swimmer& sw : swmrs) {
            QString text = sw.getName() + " " + QString::number(sw.age) + " " + 
                          sw.seedtime + " " + sw.sex;
            list->addItem(text);
        }
    }

    void sexLoad() {
        QVector<Swimmer> swmrsCopy = swmrs;
        swmrsCopy = sbySex(swmrsCopy);
        fillList(rightList, swmrsCopy);
    }

    void shallowCopy() {
        QVector<Swimmer>& swmrsCopy = swmrs;
        QVector<Swimmer> sw = sbySex(swmrsCopy);
        fillList(rightList, sw);
    }

    void clone() {
        QVector<Swimmer> swmrsCopy = swmrs;
        QVector<Swimmer> sw = sbySex(swmrsCopy);
        fillList(rightList, sw);
    }

    QVector<Swimmer> sbySex(QVector<Swimmer>& swmrs) {
        for (int i = 0; i < swmrs.size(); i++) {
            for (int j = i; j < swmrs.size(); j++) {
                if (swmrs[i].sex > swmrs[j].sex) {
                    std::swap(swmrs[i], swmrs[j]);
                }
            }
        }
        return swmrs;
    }

    void refreshLeft() {
        leftList->clear();
        fillList(leftList, swmrs);
    }

    // Sorts the swimmers by seed time
    QVector<Swimmer> sortUpwards() {
        QVector<Swimmer> swmrs;
        
        for (const Swimmer& swmr : swimmers) {
            swmrs.append(swmr);
        }
        
        for (int i = 0; i < swmrs.size(); i++) {
            for (int j = i; j < swmrs.size(); j++) {
                if (swmrs[i].time > swmrs[j].time) {
                    std::swap(swmrs[i], swmrs[j]);
                }
            }
        }
        return swmrs;
    }

private:
    QListWidget* leftList;
    QListWidget* rightList;
    CloneButton* cloneButton;
    CopyButton* copyButton;
    RefreshButton* refreshButton;
    ReloadButton* reloadButton;
    
    QVector<Swimmer> swimmers;
    QVector<Swimmer> swmrs;
};

void ReloadButton::comd() {
    bldr->reloadLeft();
}

void CopyButton::comd() {
    bldr->shallowCopy();
}

void RefreshButton::comd() {
    bldr->refreshLeft();
}

void CloneButton::comd() {
    bldr->clone();
}

// main begins here
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BuildUI builder;
    builder.show();
    return app.exec();
}

#include "Proto.moc"
