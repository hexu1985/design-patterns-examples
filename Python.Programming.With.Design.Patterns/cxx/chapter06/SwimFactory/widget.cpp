#include "widget.h"
#include <QHBoxLayout>

#include "TimedFinalEvent.h"
#include "PrelimEvent.h"
#include "Seeding.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
    QHBoxLayout* layout = new QHBoxLayout(this);

    listEvents = new QListWidget;
    listSwimmers = new QListWidget;

    listEvents->addItem("500 Free");
    listEvents->addItem("100 Free");

    layout->addWidget(listEvents);
    layout->addWidget(listSwimmers);

    // 使用 lambda 连接信号，避免手动定义槽函数
    connect(listEvents, &QListWidget::itemClicked, [this](QListWidgetItem* item) {
            onEventSelected(item);
            });

    setWindowTitle("Seeding");
    resize(400, 300);
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
    listSwimmers->clear();
    for (const auto& sw : swimmers) {
        QString text = QString("%1 %2 %3 %4 %5")
            .arg(sw.heat)
            .arg(sw.lane)
            .arg(sw.getName().c_str())
            .arg(sw.age)
            .arg(sw.seedtime.c_str());
        listSwimmers->addItem(text);
    }
}
