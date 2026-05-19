#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <memory>

// -------------------------- BlueLabel --------------------------
class BlueLabel : public QLabel {
public:
    BlueLabel(QWidget* parent, const QString& text = "")
        : QLabel(text, parent) {
        setStyleSheet("QLabel { color: blue; }");
    }
};

// -------------------------- Namer 及其派生类 --------------------------
class Namer {
public:
    QString first;
    QString last;
    virtual ~Namer() = default;
};

class FirstFirst : public Namer {
public:
    FirstFirst(const QString& namestring) {
        int i = namestring.indexOf(' ');
        if (i > 0) {
            first = namestring.left(i);
            last = namestring.mid(i + 1);
        } else {
            last = namestring;
        }
    }
};

class LastFirst : public Namer {
public:
    LastFirst(const QString& namestring) {
        int i = namestring.indexOf(',');
        if (i > 0) {
            last = namestring.left(i);
            first = namestring.mid(i + 1);
            // 移除可能的空格
            if (!first.isEmpty() && first[0] == ' ') {
                first = first.mid(1);
            }
        } else {
            last = namestring;
        }
    }
};

// -------------------------- NamerFactory --------------------------
class NamerFactory {
public:
    NamerFactory(const QString& namestring) : name(namestring) {}

    std::unique_ptr<Namer> getNamer() {
        if (name.contains(',')) {
            return std::make_unique<LastFirst>(name);
        } else {
            return std::make_unique<FirstFirst>(name);
        }
    }
private:
    QString name;
};

// -------------------------- Builder --------------------------
class Builder: public QObject {
    Q_OBJECT   // 需要信号槽支持
public:
    void clearPanel() {
        frname->clear();
        lname->clear();
        entry->clear();
    }

    void compute() {
        QString name = entry->text();
        NamerFactory factory(name);
        std::unique_ptr<Namer> namer = factory.getNamer();
        frname->setText(namer->first);
        lname->setText(namer->last);
    }

    void buildUI() {
        root = new QWidget();
        root->setWindowTitle("Simple Factory");

        QGridLayout* layout = new QGridLayout(root);

        // row 0: 提示标签 (columnspan=3)
        BlueLabel* prompt = new BlueLabel(root, "Enter name");
        layout->addWidget(prompt, 0, 0, 1, 3);

        // row 1: 输入框 (columnspan=3)
        entry = new QLineEdit(root);
        layout->addWidget(entry, 1, 0, 1, 3);

        // row 2: First name 标签和输入框
        BlueLabel* firstLabel = new BlueLabel(root, "First name:");
        layout->addWidget(firstLabel, 2, 0, 1, 1, Qt::AlignLeft);
        frname = new QLineEdit(root);
        layout->addWidget(frname, 2, 1, 1, 1, Qt::AlignRight);
        // 添加 pady=10 效果（设置行高）
        layout->setRowMinimumHeight(2, 30);

        // row 3: Last name 标签和输入框
        BlueLabel* lastLabel = new BlueLabel(root, "Last name:");
        layout->addWidget(lastLabel, 3, 0, 1, 1, Qt::AlignLeft);
        lname = new QLineEdit(root);
        layout->addWidget(lname, 3, 1, 1, 1, Qt::AlignRight);
        layout->setRowMinimumHeight(3, 25);   // pady=5 近似

        // row 4: 三个按钮
        QPushButton* btcompute = new QPushButton("Compute", root);
        QPushButton* btclear   = new QPushButton("Clear", root);
        QPushButton* btquit    = new QPushButton("Quit", root);

        layout->addWidget(btcompute, 4, 0);
        layout->addWidget(btclear,   4, 1);
        layout->addWidget(btquit,    4, 2);
        layout->setRowMinimumHeight(4, 25);   // pady=5

        // 信号槽连接
        QObject::connect(btcompute, &QPushButton::clicked,
                         this, &Builder::compute);
        QObject::connect(btclear, &QPushButton::clicked,
                         this, &Builder::clearPanel);
        QObject::connect(btquit, &QPushButton::clicked,
                         &QApplication::quit);

        root->setLayout(layout);
        root->show();
    }

    QWidget* getRoot() const { return root; }

private:
    QWidget* root = nullptr;
    QLineEdit* entry = nullptr;
    QLineEdit* frname = nullptr;
    QLineEdit* lname = nullptr;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Builder bld;
    bld.buildUI();
    return app.exec();
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "NameUI.moc"
