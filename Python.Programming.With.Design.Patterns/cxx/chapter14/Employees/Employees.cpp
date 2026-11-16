#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QString>
#include <QList>
#include <QDebug>
#include <cstdlib>

class Tree {
public:
    static QTreeWidget* tree;
    static int index;
    static int column;
};
QTreeWidget* Tree::tree = nullptr;
int Tree::index = 0;
int Tree::column = 0;

class Employee {
public:
    QString name;
    int salary;
    bool isleaf;

    Employee(const QString& n, int s) : name(n), salary(s), isleaf(true) {}
    virtual ~Employee() {}

    virtual int getSalaries() { return salary; }
    virtual QList<Employee*>* getSubordinates() { return nullptr; }
};

class Boss : public Employee {
public:
    QList<Employee*> subordinates;

    Boss(const QString& n, int s) : Employee(n, s) {
        isleaf = false;
    }
    ~Boss() {
        for (Employee* e : subordinates) delete e;
    }

    QList<Employee*>* getSubordinates() override { return &subordinates; }
    void add(Employee* e) { subordinates.append(e); }

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

class SalaryButton : public DButton {
public:
    Boss* boss;
    QLineEdit* entry;

    SalaryButton(QWidget* master, Boss* b, QLineEdit* e)
        : DButton(master), boss(b), entry(e) {
        setText("Salaries");
    }

    void comd() override {
        QTreeWidgetItem* curitem = Tree::tree->currentItem();
        if (!curitem) return;
        QString name = curitem->text(0);

        Boss* newEmp = nullptr;
        if (name == boss->name) {
            qDebug() << name << boss->name;
            newEmp = boss;
        } else {
            newEmp = boss->getChild(name);
        }
        if (!newEmp) return;
        int sum = newEmp->getSalaries();

        entry->clear();
        entry->insert(QString::number(sum));
    }
};

class Builder {
public:
    QWidget* root;

    Builder(QWidget* r) : root(r) {
        root->setGeometry(100, 100, 200, 300);
        root->setWindowTitle("Employee tree");
    }

    void build() {
        srand(2);
        Boss* boss = new Boss("CEO", 200000);

        Boss* marketVP = new Boss("Marketing_VP", 100000);
        boss->add(marketVP);
        Boss* prodVP = new Boss("Production_VP", 100000);
        boss->add(prodVP);
        Boss* salesMgr = new Boss("Sales_Mgr", 50000);
        marketVP->add(salesMgr);
        Boss* advMgr = new Boss("Advt_Mgr", 50000);
        marketVP->add(advMgr);

        for (int i = 0; i < 6; i++) {
            salesMgr->add(new Employee("Sales_" + QString::number(i),
                                      int(30000.0 + (rand() / (double)RAND_MAX) * 10000)));
        }
        advMgr->add(new Employee("Secy", 20000));

        Boss* prodMgr = new Boss("Prod_Mgr", 40000);
        prodVP->add(prodMgr);
        Boss* shipMgr = new Boss("Ship_Mgr", 35000);
        prodVP->add(shipMgr);

        for (int i = 0; i < 4; i++) {
            prodMgr->add(new Employee("Manuf_" + QString::number(i),
                                      int(25000 + (rand() / (double)RAND_MAX) * 5000)));
        }
        for (int i = 0; i < 4; i++) {
            shipMgr->add(new Employee("Ship_Clrk_" + QString::number(i),
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
        salbutton->setText("Salaries");

        layout->addWidget(tree);
        layout->addWidget(salbutton);
        layout->addWidget(entry);

        boss->makeTree(tree);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget root;
    Builder bui(&root);
    bui.build();
    root.show();
    return app.exec();
}

#include "Employees.moc"
