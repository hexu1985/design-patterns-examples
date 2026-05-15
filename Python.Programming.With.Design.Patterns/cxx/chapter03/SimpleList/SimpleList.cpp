#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDir>
#include <QDebug>

const QString DATA_FILE = "States.txt";

// ------------------------- State 类 -------------------------
class State {
public:
    State(const QString& stateString) {
        QStringList tokens = stateString.split(",");
        if (tokens.size() > 3) {
            statename = tokens[0];
            abbrev = tokens[1];
            founded = tokens[2];
            capital = tokens[3];
        }
    }

    QString getStateName() const { return statename; }
    QString toString() const { return statename; }
    QString getCapital() const { return capital; }
    QString getAbbrev() const { return abbrev; }

private:
    QString statename;
    QString abbrev;
    QString founded;
    QString capital;
};

// ------------------------- StateList 类 -------------------------
class StateList {
public:
    StateList(const QString& stateFile) {
        QFile file(stateFile);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning() << "Cannot open file:" << stateFile;
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty()) {
                State* state = new State(line);
                states.append(state);
            }
        }
        file.close();
    }

    QStringList getText() const {
        QStringList list;
        for (State* s : states)
            list << s->toString();
        return list;
    }

    QList<State*> getStateList() const { return states; }

private:
    QList<State*> states;
};

// ------------------------- BuildUI 类 -------------------------
class BuildUI : public QWidget {
public:
    BuildUI(QWidget* parent, const QList<State*>& stateList)
        : QWidget(parent), states(stateList) {

        QGridLayout* layout = new QGridLayout(this);

        listbox = new QListWidget(this);
        listbox->setSelectionMode(QAbstractItemView::SingleSelection);
        layout->addWidget(listbox, 0, 0, 4, 1);
        layout->setColumnMinimumWidth(0, 10);   // padx=10

        for (State* state : states) {
            listbox->addItem(state->getStateName());
        }

        setLayout(layout);
    }

private:
    QList<State*> states;
    QListWidget* listbox;
};

// ------------------------- main -------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 获取程序所在目录，拼接 States.txt
    QString filePath = QDir(QApplication::applicationDirPath()).absoluteFilePath(DATA_FILE);
    StateList sl(filePath);          // 加载数据
    if (sl.getStateList().isEmpty()) {
        qWarning() << "No states loaded. Check" << DATA_FILE;
        return -1;
    }

    // 主窗口
    QWidget root;
    root.setWindowTitle("Simple State List");
    root.setFixedSize(300, 200);     // geometry("300x200")

    BuildUI bdui(&root, sl.getStateList());

    root.show();
    return app.exec();               // mainloop()
}