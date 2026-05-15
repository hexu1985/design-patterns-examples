#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QScrollBar>
#include <QLineEdit>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QKeyEvent>

const QString DATA_FILE = "States.txt";

// ========================= State 类 =========================
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
    QString getFounded() const { return founded; }

private:
    QString statename;
    QString abbrev;
    QString founded;
    QString capital;
};

// ========================= StateList 类 =========================
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

// ========================= BuildUI 类 =========================
class BuildUI : public QWidget {
    Q_OBJECT   // 需要信号槽支持

public:
    BuildUI(QWidget* parent, const QList<std::shared_ptr<State>>& stateList)
        : QWidget(parent), states(stateList) {

        QGridLayout* layout = new QGridLayout(this);

        // --- 创建 Listbox (QListWidget) ---
        listbox = new QListWidget(this);
        listbox->setSelectionMode(QAbstractItemView::SingleSelection);
        layout->addWidget(listbox, 0, 0, 4, 1);   // rowspan=4, column=0
        layout->setColumnMinimumWidth(0, 10);     // padx=10

        // 填充州名
        for (const auto& s : states)
            listbox->addItem(s->getStateName());

        // --- 创建 Entry 输入框（底部）---
        entry = new QLineEdit(this);
        layout->addWidget(entry, 4, 0);           // row=4, column=0
        layout->setVerticalSpacing(4);            // pady=4
        entry->setFocus();                        // focus_set()

        // --- 创建右侧四个标签 ---
        lbstate = new QLabel("", this);
        lbabbrev = new QLabel("", this);
        lbcapital = new QLabel("", this);
        lbfounded = new QLabel("", this);
        lbabbrev->setStyleSheet("QLabel { color: red; }");   // foreground="red"

        layout->addWidget(lbstate, 0, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        layout->addWidget(lbabbrev, 1, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        layout->addWidget(lbcapital, 2, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);
        layout->addWidget(lbfounded, 3, 2, 1, 1, Qt::AlignLeft | Qt::AlignTop);

#if 0
        // --- 创建自定义 ScrollBar，并与 listbox 关联 ---
        scrollBar = new QScrollBar(this);
        scrollBar->setOrientation(Qt::Vertical);
        layout->addWidget(scrollBar, 0, 1, 4, 1);   // 放在第1列，行0-3
        // 连接 scrollBar 和 listbox 的滚动条
        connect(scrollBar, &QScrollBar::valueChanged,
                listbox->verticalScrollBar(), &QScrollBar::setValue);
        connect(listbox->verticalScrollBar(), &QScrollBar::valueChanged,
                scrollBar, &QScrollBar::setValue);
        // 设置滚动条范围
        scrollBar->setRange(0, listbox->verticalScrollBar()->maximum());
        // 当 listbox 内容变化时更新滚动条范围
        connect(listbox->verticalScrollBar(), &QScrollBar::rangeChanged,
                scrollBar, &QScrollBar::setRange);
        // 初始同步
        scrollBar->setValue(listbox->verticalScrollBar()->value());
        // 显示滚动条样式（可选）
        scrollBar->show();
#endif        

        // --- 信号/槽绑定 ---
        // listbox 选择变化 -> lbselect
        connect(listbox, &QListWidget::currentRowChanged,
                this, &BuildUI::lbselect);
        // entry 按键事件（通过安装事件过滤器来捕获所有按键）
        entry->installEventFilter(this);

        // 设置布局
        setLayout(layout);
    }

protected:
    bool eventFilter(QObject* obj, QEvent* event) override {
        if (obj == entry && event->type() == QEvent::KeyPress) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            QString text = keyEvent->text();
            if (!text.isEmpty() && text[0].isLetterOrNumber()) {
                char ch = text[0].toUpper().toLatin1();
                keyPress(ch);
                //return true;   // 事件已处理
            }
        }
        return QWidget::eventFilter(obj, event);
    }

private slots:
    // 对应原 lbselect 方法
    void lbselect(int row) {
        if (row >= 0 && row < states.size()) {
            auto state = states[row];
            loadLabels(state);
        }
    }

    // 键盘搜索并高亮
    void keyPress(char ch) {
        int i = 0;
        bool found = false;
        while (!found && i < states.size()) {
            found = states[i]->getStateName().startsWith(ch, Qt::CaseInsensitive);
            if (!found)
                ++i;
        }
        if (found) {
            listbox->clearSelection();
            listbox->setCurrentRow(i);
            listbox->scrollToItem(listbox->item(i), QAbstractItemView::EnsureVisible);
            loadLabels(states[i]);
        }
    }

    void loadLabels(const std::shared_ptr<State>& state) {
        lbstate->setText(state->getStateName());
        lbcapital->setText(state->getCapital());
        lbabbrev->setText(state->getAbbrev());
        lbfounded->setText(state->getFounded());
    }

private:
    QList<std::shared_ptr<State>> states;
    QListWidget* listbox;
    QLineEdit* entry;
    QScrollBar* scrollBar;
    QLabel* lbstate;
    QLabel* lbabbrev;
    QLabel* lbcapital;
    QLabel* lbfounded;
};

// ========================= main =========================
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 获取 States.txt 的完整路径（与可执行文件同目录）
    QString filePath = QDir(QCoreApplication::applicationDirPath()).absoluteFilePath(DATA_FILE);
    StateList sl(filePath);
    if (sl.getStateList().isEmpty()) {
        qWarning() << "No states loaded. Check" << DATA_FILE;
        return -1;
    }

    QWidget root;
    root.setWindowTitle("State List");
    root.setFixedSize(300, 300);          // geometry("300x200")

    BuildUI bdui(&root, sl.getStateList());

    root.show();
    return app.exec();                    // mainloop()
}

// 因为类中使用了 Q_OBJECT，需要在包含 moc 生成的文件
#include "StateListBox.moc"
