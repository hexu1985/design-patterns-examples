#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QHeaderView>
#include <QDebug>
#include <vector>
#include <string>

#include "SwimClasses.hpp"

// -------------------------- BuildUI 类 --------------------------
class BuildUI : public QWidget {
    Q_OBJECT

public:
    BuildUI(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Seeding");
        build();
    }

private slots:
    // 回调函数：当左侧列表选中项变化时调用
    void evselect(int row) {
        // 根据选中的行决定加载哪个项目
        Event* event = nullptr;
        if (row <= 0) {
            event = new TimedFinalEvent("500free.txt", 6);
        } else {
            event = new PrelimEvent("100free.txt", 6);
        }

        if (event) {
            Seeding* seeding = event->getSeeding();
            std::vector<Swimmer*> swmrs = seeding->getSwimmers();

            // 清空 TreeView
            swlist->clear();

            // 加载新数据到 TreeView
            int rowNum = 1;
            for (Swimmer* sw : swmrs) {
                QTreeWidgetItem* item = new QTreeWidgetItem(swlist);
                item->setText(0, QString::number(sw->heat).trimmed());  // H (heat)
                item->setText(1, QString::number(sw->lane));            // L (lane)
                item->setText(2, QString::fromStdString(sw->getName())); // Name
                item->setText(3, QString::number(sw->age));             // Age
                item->setText(4, QString::fromStdString(sw->seedtime)); // Seed
                rowNum++;
            }

            delete seeding;
            delete event;
        }
    }

    void build() {
        //setFixedSize(400, 200);          // root.geometry("400x200")
        resize(400, 200);          // ✅ 设置初始尺寸，但允许用户拉伸
        setMinimumSize(400, 200);  // ✅ 可选：限制最小尺寸

        QGridLayout* layout = new QGridLayout(this);

        // 左侧列表：项目选择
        evlist = new QListWidget(this);
        evlist->addItem("500 Free");
        evlist->addItem("100 Free");
        layout->addWidget(evlist, 0, 0);

        // 绑定选择变化信号
        connect(evlist, &QListWidget::currentRowChanged,
                this, &BuildUI::evselect);

        // 右侧 TreeView：显示排位后的选手（作为表格）
        swlist = new QTreeWidget(this);      
        swlist->setHeaderLabels({"H", "L", "Name", "Age", "Seed"});
        
        // 设置列宽和拉伸策略（stretch=NO）
        swlist->setColumnWidth(0, 40);   // H (heat)
        swlist->setColumnWidth(1, 30);   // L (lane)
        swlist->setColumnWidth(2, 100);  // Name
        swlist->setColumnWidth(3, 40);   // Age
        swlist->setColumnWidth(4, 50);   // Seed
        
        // 禁止列自动拉伸
        swlist->header()->setSectionResizeMode(0, QHeaderView::Fixed);
        swlist->header()->setSectionResizeMode(1, QHeaderView::Fixed);
        swlist->header()->setSectionResizeMode(2, QHeaderView::Fixed);
        swlist->header()->setSectionResizeMode(3, QHeaderView::Fixed);
        swlist->header()->setSectionResizeMode(4, QHeaderView::Fixed);
        
        // 设置表头字体加粗（模拟 style.configure("Treeview.Heading", font=(None,10,"bold"))）
        QFont headerFont = swlist->header()->font();
        headerFont.setBold(true);
        headerFont.setPointSize(10);
        swlist->header()->setFont(headerFont);

        swlist->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        layout->addWidget(swlist, 0, 1);
        layout->setRowMinimumHeight(0, 10);        // pady=10
        //layout->setAlignment(swlist, Qt::AlignCenter);
        

        // 设置列权重（模拟 grid_columnconfigure）
        layout->setColumnStretch(0, 1);             // weight=1
        layout->setColumnStretch(1, 3);             // weight=3

        setLayout(layout);
        show();
    }

private:
    QListWidget* evlist;
    QTreeWidget* swlist;
};

// -------------------------- main --------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BuildUI window;
    return app.exec();
}

// 如果使用 Q_OBJECT 需要包含 moc 文件
#include "SwimFactoryTable.moc"