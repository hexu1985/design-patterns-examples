#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QListWidgetItem>
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

            // 清空右侧列表
            swlist->clear();

            // 加载新数据到右侧列表
            for (Swimmer* sw : swmrs) {
                QString text = QString("%1 %2 %3 %4 %5")
                    .arg(sw->heat)
                    .arg(sw->lane)
                    .arg(QString::fromStdString(sw->getName()))
                    .arg(sw->age)
                    .arg(QString::fromStdString(sw->seedtime));
                swlist->addItem(text);
            }

            delete seeding;
            delete event;
        }
    }

    void build() {
        setFixedSize(325, 200);          // root.geometry("325x200")

        QGridLayout* layout = new QGridLayout(this);

        // 左侧列表：项目选择
        evlist = new QListWidget(this);
        evlist->addItem("500 Free");
        evlist->addItem("100 Free");
        layout->addWidget(evlist, 0, 0);

        // 绑定选择变化信号
        connect(evlist, &QListWidget::currentRowChanged,
                this, &BuildUI::evselect);

        // 右侧列表：显示排位后的选手
        swlist = new QListWidget(this);
        layout->addWidget(swlist, 0, 1);
        layout->setRowMinimumHeight(0, 10);        // pady=10
        layout->setAlignment(swlist, Qt::AlignCenter);

        // 设置列权重（模拟 grid_columnconfigure）
        layout->setColumnStretch(0, 1);             // weight=1
        layout->setColumnStretch(1, 3);             // weight=3

        setLayout(layout);
        show();
    }

private:
    QListWidget* evlist;
    QListWidget* swlist;
};

// -------------------------- main --------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BuildUI window;
    return app.exec();
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "SwimFactory.moc"