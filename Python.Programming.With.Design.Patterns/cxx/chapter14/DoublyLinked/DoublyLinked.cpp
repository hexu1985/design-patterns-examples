// Employees.cpp
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QDebug>
#include <cstdlib>

// ===================== Tree 静态辅助类 =====================
class Tree {
public:
    static QTreeWidget* tree;
    static int index;
    static int column;
};
QTreeWidget* Tree::tree = nullptr;
int Tree::index = 0;
int Tree::column = 0;

// ===================== Employee 基类 =====================
class Boss; // 前向声明

class Employee {
public:
    Boss* parent;
    QString name;
    int salary;
    bool isleaf;

    Employee(Boss* p, const QString& n, int s)
        : parent(p), name(n), salary(s), isleaf(true) {}
    virtual ~Employee() {}

    virtual int getSalaries() { return salary; }
    virtual QList<Employee*>* getSubordinates() { return nullptr; }
};

// ===================== Boss 派生类 =====================
class Boss : public Employee {
public:
    QList<Employee*> subordinates;

    Boss(Boss* p, const QString& n, int s) : Employee(p, n, s) {
        isleaf = false;
    }
    ~Boss() {
        for (Employee* e : subordinates) delete e;
    }

    void add(Employee* e) { subordinates.append(e); }

    QList<Employee*>* getSubordinates() override { return &subordinates; }

    int getSalaries() override {
        int sum = salary;
        for (Employee* e : subordinates) {
            sum += e->getSalaries();
        }
        return sum;
    }

    void makeTree(QTreeWidget* tree) {
        Tree::index = 0;
        Tree::tree = tree;
        QTreeWidgetItem* bossnode = new QTreeWidgetItem(tree);
        bossnode->setText(0, "CEO");
        Tree::index = 1;
        addNodes(bossnode, this);
    }

    void addNodes(QTreeWidgetItem* pnode, Employee* emp) {
        if (!emp->isleaf) {
            QList<Employee*>* empList = emp->getSubordinates();
            if (empList != nullptr) {
                for (Employee* newEmp : *empList) {
                    QTreeWidgetItem* newnode = new QTreeWidgetItem();
                    newnode->setText(0, newEmp->name);
                    pnode->addChild(newnode);
                    addNodes(newnode, newEmp);
                }
            }
        }
    }

    Boss* getChild(const QString& name) {
        if (this->name == name) return this;
        bool found = false;
        int i = 0;
        Employee* newEmp = nullptr;
        while (!found && i < subordinates.size()) {
            newEmp = subordinates[i];
            found = (newEmp->name == name);
            if (!found) {
                if (!newEmp->isleaf) {
                    newEmp = static_cast<Boss*>(newEmp)->getChild(name);
                } else {
                    newEmp = nullptr;
                }
            }
            found = (newEmp != nullptr);
            i++;
        }
        return found ? static_cast<Boss*>(newEmp) : nullptr;
    }

    // 根据选中项名字查找匹配 Employee
    Employee* findMatch() {
        QTreeWidgetItem* curitem = Tree::tree->currentItem();
        if (!curitem) return nullptr;
        QString name = curitem->text(0);

        if (name == this->name) {
            qDebug() << name << this->name;
            return this;
        }
        return getChild(name);
    }
};

// ===================== DButton 基类 =====================
class DButton : public QPushButton {
    Q_OBJECT

public:
    DButton(QWidget* parent = nullptr) : QPushButton(parent) {
        connect(this, &QPushButton::clicked, this, &DButton::comd);
    }

    // Abstract method to be called by children
    virtual void comd() = 0;
};

// ===================== ReportButton =====================
class ReportButton : public DButton {
public:
    Boss* boss;

    ReportButton(QWidget* master, Boss* b) : DButton(master), boss(b) {
        setText("Chain");
    }

    void comd() override {
        Employee* emp = boss->findMatch();
        if (!emp) return;

        bool quit = false;
        QString mesg = "";
        while (!quit) {
            mesg += emp->name + "\n";
            emp = emp->parent;
            quit = (emp == nullptr || emp->name == "CEO");
        }
        if (emp != nullptr) {
            mesg += emp->name + "\n";
            QMessageBox::information(this, "Report chain", mesg);
        } else {
            QMessageBox::information(this, "no boss", "CEO has no boss");
        }
    }
};

// ===================== SalaryButton =====================
class SalaryButton : public DButton {
public:
    Boss* boss;
    QLineEdit* entry;

    SalaryButton(QWidget* master, Boss* b, QLineEdit* e)
        : DButton(master), boss(b), entry(e) {
        setText("Salaries");
    }

    void comd() override {
        Employee* newEmp = boss->findMatch();
        if (!newEmp) return;
        int sum = newEmp->getSalaries();

        entry->clear();
        entry->insert(QString::number(sum));
    }
};

// ===================== Builder =====================
class Builder {
public:
    QWidget* root;

    Builder(QWidget* r) : root(r) {
        root->setGeometry(100, 100, 200, 300);
        root->setWindowTitle("Employee tree");
    }

    void build() {
        srand(2);
        Boss* boss = new Boss(nullptr, "CEO", 200000);

        Boss* marketVP = new Boss(boss, "Marketing_VP", 100000);
        boss->add(marketVP);
        Boss* prodVP = new Boss(boss, "Production_VP", 100000);
        boss->add(prodVP);
        Boss* salesMgr = new Boss(marketVP, "Sales_Mgr", 50000);
        marketVP->add(salesMgr);
        Boss* advMgr = new Boss(marketVP, "Advt_Mgr", 50000);
        marketVP->add(advMgr);

        for (int i = 0; i < 6; i++) {
            salesMgr->add(new Employee(salesMgr, "Sales_" + QString::number(i),
                                      int(30000.0 + (rand() / (double)RAND_MAX) * 10000)));
        }
        advMgr->add(new Employee(advMgr, "Secy", 20000));

        Boss* prodMgr = new Boss(prodVP, "Prod_Mgr", 40000);
        prodVP->add(prodMgr);
        Boss* shipMgr = new Boss(prodVP, "Ship_Mgr", 35000);
        prodVP->add(shipMgr);

        for (int i = 0; i < 4; i++) {
            prodMgr->add(new Employee(prodMgr, "Manuf_" + QString::number(i),
                                      int(25000 + (rand() / (double)RAND_MAX) * 5000)));
        }
        for (int i = 0; i < 4; i++) {
            shipMgr->add(new Employee(shipMgr, "Ship_Clrk_" + QString::number(i),
                                      int(20000 + (rand() / (double)RAND_MAX) * 5000)));
        }

        buildUI(boss);
    }

    void buildUI(Boss* boss) {
        QVBoxLayout* layout = new QVBoxLayout(root);
        root->setLayout(layout);

        QTreeWidget* tree = new QTreeWidget(root);
        tree->setColumnCount(1);
        tree->setHeaderHidden(true);
        tree->setColumnWidth(0, 150);

        QLineEdit* entry = new QLineEdit(root);
        SalaryButton* salbutton = new SalaryButton(root, boss, entry);
        ReportButton* reptbuttom = new ReportButton(root, boss);

        layout->addWidget(tree);
        layout->addWidget(salbutton);
        layout->addWidget(entry);
        layout->addWidget(reptbuttom);

        boss->makeTree(tree);
    }
};

// ===================== main =====================
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget root;
    Builder bui(&root);
    bui.build();
    root.show();
    return app.exec();
}

#include "DoublyLinked.moc"