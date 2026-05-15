#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QFile>
#include <QTextStream>
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
    QString getCapital() const { return capital; }
    QString getAbbrev() const { return abbrev; }
    QString getFounded() const { return founded; }

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
                auto state = std::make_shared<State>(line);
                states.append(state);
            }
        }
        file.close();
    }

    QStringList getText() const {
        QStringList list;
        for (const auto& s : states)
            list << s->getStateName();
        return list;
    }

    const QList<std::shared_ptr<State>>& getStateList() const { return states; }

private:
    QList<std::shared_ptr<State>> states;
};

// ------------------------- BuildUI 类 -------------------------
class BuildUI : public QWidget {
    Q_OBJECT        
public:
    BuildUI(QWidget* parent, const QList<std::shared_ptr<State>>& stateList)
        : QWidget(parent), states(stateList) {

        QGridLayout* layout = new QGridLayout(this);

        // 创建下拉列表（ComboBox）
        QStringList names;
        for (const auto& s : states)
            names << s->getStateName();
        combo = new QComboBox(this);
        combo->addItems(names);
        combo->setCurrentIndex(0);
        layout->addWidget(combo, 0, 0, 8, 1);   // rowspan=8, column=0
        layout->setColumnMinimumWidth(0, 10);    // padx=10

        // 创建右侧四个标签
        lbstate = new QLabel("", this);
        lbabbrev = new QLabel("", this);
        lbcapital = new QLabel("", this);
        lbfounded = new QLabel("", this);

        lbabbrev->setStyleSheet("QLabel { color: red; }");  // foreground="red"

        layout->addWidget(lbstate, 0, 2, 1, 1, Qt::AlignTop | Qt::AlignLeft);    // sticky=NW
        layout->addWidget(lbabbrev, 1, 2, 1, 1, Qt::AlignTop | Qt::AlignLeft);
        layout->addWidget(lbcapital, 2, 2, 1, 1, Qt::AlignTop | Qt::AlignLeft);
        layout->addWidget(lbfounded, 3, 2, 1, 1, Qt::AlignTop | Qt::AlignLeft);

        setLayout(layout);

        // 绑定信号：当下拉列表当前索引改变时调用 onselect
        connect(combo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                this, &BuildUI::onselect);

        // 初始加载第一个州
        if (!states.isEmpty())
            loadLabels(states[0]);
    }

private slots:
    void onselect(int index) {
        if (index >= 0 && index < states.size())
            loadLabels(states[index]);
    }

    void loadLabels(const std::shared_ptr<State>& state) {
        lbstate->setText(state->getStateName());
        lbcapital->setText(state->getCapital());
        lbabbrev->setText(state->getAbbrev());
        lbfounded->setText(state->getFounded());
    }

private:
    QList<std::shared_ptr<State>> states;
    QComboBox* combo;
    QLabel* lbstate;
    QLabel* lbabbrev;
    QLabel* lbcapital;
    QLabel* lbfounded;
};

// ------------------------- main -------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 加载州数据（假设 States.txt 位于当前工作目录）
    StateList sl(DATA_FILE);
    if (sl.getStateList().isEmpty()) {
        qWarning() << "No states loaded. Check" << DATA_FILE;
        return -1;
    }

    QWidget root;
    root.setWindowTitle("State List");
    root.setFixedSize(300, 200);            // 对应 geometry("300x200")

    BuildUI bdui(&root, sl.getStateList());

    root.show();
    return app.exec();                      // mainloop()
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "StateDisplayCombo.moc"