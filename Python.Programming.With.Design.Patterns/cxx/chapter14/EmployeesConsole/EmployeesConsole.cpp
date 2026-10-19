#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cctype>
#include <algorithm>

// 前向声明
class Employee;
class Boss;

// Employee 是基类
class Employee {
protected:
    std::string name;
    int salary;
    bool isleaf;

public:
    Employee(const std::string& name, int salary) : name(name), salary(salary), isleaf(true) {}
    virtual ~Employee() {}

    virtual int getSalaries() {
        return salary;
    }

    virtual std::vector<Employee*>* getSubordinates() {
        return nullptr;
    }

    std::string getName() const { return name; }
    int getSalary() const { return salary; }
    bool getIsLeaf() const { return isleaf; }
};

// Boss 继承自 Employee。只有 Boss 才有下属
class Boss : public Employee {
private:
    std::vector<Employee*> subordinates;
    int indent;

public:
    Boss(const std::string& name, int salary) : Employee(name, salary), indent(0) {
        isleaf = false;
    }

    ~Boss() {
        for (auto e : subordinates) {
            delete e;
        }
    }

    std::vector<Employee*>* getSubordinates() override {
        return &subordinates;
    }

    void add(Employee* e) {
        subordinates.push_back(e);
    }

    // 递归调用，向下遍历树
    int getSalaries() override {
        int sum = salary;
        for (auto e : subordinates) {
            sum += e->getSalaries();
        }
        return sum;
    }

    // 为员工结构创建树
    void makeTree() {
        indent = 0;
        std::cout << name << " " << salary << std::endl;
        addNodes(this);
    }

    // 递归打印员工树，向下遍历树
    void addNodes(Employee* emp) {
        if (!emp->getIsLeaf()) { // Boss 不是叶子节点
            std::vector<Employee*>* empList = emp->getSubordinates();
            if (empList != nullptr) { // 必须是 Boss
                for (auto newEmp : *empList) {
                    std::cout << std::string(indent, ' ') << newEmp->getName() << " " << newEmp->getSalary() << std::endl;
                    indent += 2;
                    addNodes(newEmp);
                    indent -= 2;
                }
            }
        }
    }

    // 查找名称匹配的子节点
    Employee* getChild(const std::string& name) {
        if (this->name == name) {
            return this;
        } else {
            bool found = false;
            size_t index = 0;
            Employee* newEmp = nullptr;
            while (!found && index < subordinates.size()) {
                newEmp = subordinates[index];
                std::string lower1 = newEmp->getName();
                std::string lower2 = name;
                std::transform(lower1.begin(), lower1.end(), lower1.begin(), ::tolower);
                std::transform(lower2.begin(), lower2.end(), lower2.begin(), ::tolower);
                found = (lower1 == lower2);

                if (!found) {
                    if (!newEmp->getIsLeaf()) {
                        newEmp = static_cast<Boss*>(newEmp)->getChild(name);
                    } else {
                        newEmp = nullptr;
                    }
                }
                found = (newEmp != nullptr);
                index++;
            }

            if (found) {
                return newEmp;
            } else {
                return nullptr;
            }
        }
    }
};

// 计算选定员工薪资的类
class SalarySpan {
private:
    Boss* boss;
    std::string name;

public:
    SalarySpan(Boss* boss, const std::string& name) : boss(boss), name(name) {}

    void print() {
        Employee* newEmp = nullptr;
        // 搜索匹配项
        if (name == boss->getName()) {
            std::cout << name << " " << boss->getName() << std::endl;
            newEmp = boss;
        } else {
            newEmp = boss->getChild(name);
        }
        if (newEmp != nullptr) {
            int sum = newEmp->getSalaries();
            std::cout << "Salary span for " << name << " " << sum << std::endl;
        } else {
            std::cout << "Employee not found: " << name << std::endl;
        }
    }
};

// 创建员工树结构
// 薪资部分使用随机数生成
class Builder {
private:
    Boss* boss;

public:
    Builder() : boss(nullptr) {}

    ~Builder() {
        delete boss;
    }

    // 构建员工树
    void build() {
        srand(2); // 初始化随机种子
        boss = new Boss("CEO", 200000);
        // 在 Boss 下添加 VP
        Boss* marketVP = new Boss("Marketing_VP", 100000);
        boss->add(marketVP);
        Boss* prodVP = new Boss("Production_VP", 100000);
        boss->add(prodVP);
        Boss* salesMgr = new Boss("Sales_Mgr", 50000);
        marketVP->add(salesMgr);
        Boss* advMgr = new Boss("Advt_Mgr", 50000);
        marketVP->add(advMgr);

        // 添加向 Sales Mgr 汇报的销售员
        for (int i = 0; i < 6; i++) {
            salesMgr->add(new Employee("Sales_" + std::to_string(i),
                30000 + rand() % 10000));
        }
        advMgr->add(new Employee("Secy", 20000));
        Boss* prodMgr = new Boss("Prod_Mgr", 40000);
        prodVP->add(prodMgr);
        Boss* shipMgr = new Boss("Ship_Mgr", 35000);
        prodVP->add(shipMgr);

        // 添加制造和运输员工
        for (int i = 0; i < 4; i++) {
            prodMgr->add(new Employee("Manuf_" + std::to_string(i),
                25000 + rand() % 5000));
        }
        for (int i = 0; i < 4; i++) {
            shipMgr->add(new Employee("Ship_Clrk_" + std::to_string(i),
                20000 + rand() % 5000));
        }

        buildTree(boss);
    }

    // 创建树
    void buildTree(Boss* boss) {
        boss->makeTree();
        std::string ename;
        while (true) {
            std::cout << "Enter employee name for salary span (q for quit): ";
            std::getline(std::cin, ename);
            if (ename == "q") {
                break;
            }
            SalarySpan span(boss, ename);
            span.print();
        }
    }
};

// --程序从这里开始---
int main() {
    Builder bui;
    bui.build();
    return 0;
}

