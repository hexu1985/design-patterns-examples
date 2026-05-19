#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QHeaderView>
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
            founded   = tokens[2];
            capital   = tokens[3];
        }
    }

    QString getStateName() const { return statename; }
    QString getCapital()  const { return capital; }
    QString getAbbrev()   const { return abbrev; }
    QString getFounded()  const { return founded; }

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
                states.append(new State(line));
            }
        }
        file.close();
    }

    QList<State*> getStateList() const { return states; }

private:
    QList<State*> states;
};

// ======================== BuildUI 类 ========================
class BuildUI : public QWidget {
public:
    BuildUI(QWidget* parent, const QList<State*>& stateList)
        : QWidget(parent), states(stateList) {

        // 设置主窗口几何尺寸（优先使用传入的几何信息，但外部 main 可能还会设置）
        // 原代码在 BuildUI 内部设置了 root.geometry("350x200")，但 main 中又设置了 300x200，
        // 这里让外部决定，不重复设置。

        QVBoxLayout* layout = new QVBoxLayout(this);

        // 创建 TreeWidget 模拟 ttk.Treeview
        tree = new QTreeWidget(this);
        tree->setHeaderLabels({"Name", "Abbrev", "Capital", "Founded"});
        tree->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

        // 设置列宽（近似原代码）
        tree->setColumnWidth(0, 100);   // Name
        tree->setColumnWidth(1, 50);    // Abbrev
        tree->setColumnWidth(2, 100);   // Capital
        tree->setColumnWidth(3, 70);    // Founded

        // 设置表头字体加粗（模拟 Style().configure("Treeview.Heading", font=(None,10,"bold"))）
        QFont headerFont = tree->header()->font();
        headerFont.setBold(true);
        headerFont.setPointSize(10);
        tree->header()->setFont(headerFont);

        // 填充数据
        for (State* s : states) {
            QTreeWidgetItem* item = new QTreeWidgetItem(tree);
            item->setText(0, s->getStateName());
            item->setText(1, s->getAbbrev());
            item->setText(2, s->getCapital());
            item->setText(3, s->getFounded());
        }

        layout->addWidget(tree);
        // 原代码 tree.pack(side=TOP, fill=X) 对应上方布局，填满水平方向
        layout->setAlignment(tree, Qt::AlignTop);
        setLayout(layout);
    }

private:
    QList<State*> states;
    QTreeWidget* tree;
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
    root.setFixedSize(350, 200);               // 对应 BuildUI 中设置的 350x200
    BuildUI ui(&root, sl.getStateList());
    root.show();

    return app.exec();
}