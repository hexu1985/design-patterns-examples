#include "widget.h"
#include <QHBoxLayout>
#include <QHeaderView>

#include "TimedFinalEvent.h"
#include "PrelimEvent.h"
#include "Seeding.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);

    listEvents = new QListWidget;

    listEvents->addItem("500 Free");
    listEvents->addItem("100 Free");

    // 在 setupUI() 中创建表格
    tableSwimmers = new QTableWidget;
    tableSwimmers->setColumnCount(5);
    QStringList headers;
    headers << "H" << "L" << "Name" << "Age" << "Seed";
    tableSwimmers->setHorizontalHeaderLabels(headers);
    // 设置列宽（可选）
    tableSwimmers->setColumnWidth(0, 40);
    tableSwimmers->setColumnWidth(1, 40);
    tableSwimmers->setColumnWidth(2, 120);
    tableSwimmers->setColumnWidth(3, 50);
    tableSwimmers->setColumnWidth(4, 70);
    // 标题加粗
    QFont boldFont;
    boldFont.setBold(true);
    tableSwimmers->horizontalHeader()->setFont(boldFont);

    layout->addWidget(listEvents);
    layout->addWidget(tableSwimmers);

    // 使用 lambda 连接信号，避免手动定义槽函数
    connect(listEvents, &QListWidget::itemClicked, [this](QListWidgetItem* item) {
            onEventSelected(item);
            });

    setWindowTitle("Seeding");
    resize(600, 300);
}

void Widget::onEventSelected(QListWidgetItem* item) {
    int row = listEvents->row(item);
    std::unique_ptr<Event> event;
    std::unique_ptr<Seeding> seeding;
    std::vector<Swimmer> swmrs;
    if (row == 0) {
        event = std::make_unique<TimedFinalEvent>("500free.txt", 6);
    } else if (row == 1) {
        event = std::make_unique<PrelimEvent>("100free.txt", 6);
    }
    seeding.reset(event->getSeeding());
    auto swimmers = seeding->getSwimmers();
    updateSwimmersList(swimmers);
}

void Widget::updateSwimmersList(const std::vector<Swimmer>& swimmers) {
    tableSwimmers->clearContents();           // 清除内容但保留标题
    tableSwimmers->setRowCount(swimmers.size());
    for (int row = 0; row < swimmers.size(); ++row) {
        const auto& sw = swimmers[row];
        tableSwimmers->setItem(row, 0, new QTableWidgetItem(QString::number(sw.heat)));
        tableSwimmers->setItem(row, 1, new QTableWidgetItem(QString::number(sw.lane)));
        tableSwimmers->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(sw.getName())));
        tableSwimmers->setItem(row, 3, new QTableWidgetItem(QString::number(sw.age)));
        tableSwimmers->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(sw.seedtime)));
    }
}
