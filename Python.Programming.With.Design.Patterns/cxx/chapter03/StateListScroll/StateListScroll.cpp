#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDebug>

const QString DATA_FILE = "States.txt";

// ======================== State 类 ========================
class State {
public:
    State(const QString& stateString) {
        QStringList tokens = stateString.split(",");
        if (tokens.size() > 3) {
            statename = tokens[0];
            abbrev    = tokens[1];
            founded   = tokens[2];   // 虽未使用，但保留
            capital   = tokens[3];
        }
    }

    QString getStateName() const { return statename; }
    QString toString()    const { return statename; }
    QString getCapital()  const { return capital; }
    QString getAbbrev()   const { return abbrev; }

private:
    QString statename;
    QString abbrev;
    QString founded;
    QString capital;
};

// ======================== StateList 类 ========================
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

    const QList<std::shared_ptr<State>>& getStateList() const { return states; }

private:
    QList<std::shared_ptr<State>> states;
};

// ======================== BuildUI 类 ========================
class BuildUI : public QWidget {
    Q_OBJECT   // 需要信号槽支持

public:
    BuildUI(QWidget* parent, const QList<std::shared_ptr<State>>& stateList)
        : QWidget(parent), states(stateList) {

        QGridLayout* layout = new QGridLayout(this);

        // ---- 列表控件（自带滚动条）----
        listbox = new QListWidget(this);
        listbox->setSelectionMode(QAbstractItemView::SingleSelection);
        layout->addWidget(listbox, 0, 0, 4, 1);   // rowspan=4, column=0
        layout->setColumnMinimumWidth(0, 10);     // padx=10

        // 填充州名
        for (const auto& s : states)
            listbox->addItem(s->getStateName());

        // ---- 右侧三个标签 ----
        lbstate   = new QLabel("", this);
        lbabbrev  = new QLabel("", this);
        lbcapital = new QLabel("", this);
        lbabbrev->setStyleSheet("QLabel { color: red; }");  // foreground="red"

        // 使用 sticky=W (左对齐)
        layout->addWidget(lbstate,   0, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        layout->addWidget(lbabbrev,  1, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        layout->addWidget(lbcapital, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);

        // 绑定列表选择事件
        connect(listbox, &QListWidget::currentRowChanged,
                this, &BuildUI::onselect);

        setLayout(layout);
    }

private slots:
    void onselect(int row) {
        if (row >= 0 && row < states.size()) {
            auto s = states[row];
            lbstate->setText(s->getStateName());
            lbabbrev->setText(s->getAbbrev());
            lbcapital->setText(s->getCapital());
        }
    }

private:
    QList<std::shared_ptr<State>> states;
    QListWidget* listbox;
    QLabel* lbstate;
    QLabel* lbabbrev;
    QLabel* lbcapital;
};

// ======================== main ========================
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    StateList sl(DATA_FILE);
    if (sl.getStateList().isEmpty()) {
        qWarning() << "No data loaded. Check" << DATA_FILE;
        return -1;
    }

    QWidget root;
    root.setWindowTitle("State List");
    root.setFixedSize(300, 200);          // geometry("300x200")
    BuildUI ui(&root, sl.getStateList());
    root.show();

    return app.exec();                    // mainloop()
}

// 因为类中使用了 Q_OBJECT，需要在包含 moc 生成的文件
#include "StateListScroll.moc"
