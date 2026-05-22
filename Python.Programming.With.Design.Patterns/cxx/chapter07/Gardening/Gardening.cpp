#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QFrame>
#include <QGroupBox>
#include <QPainter>
#include <QStyleFactory>
#include <QDebug>

// -------------------------- Plant 类 --------------------------
class Plant {
public:
    Plant(const QString& pname) : name(pname) {}
    QString getName() const { return name; }
private:
    QString name;
};

// -------------------------- Garden 抽象基类 --------------------------
class Garden {
public:
    virtual Plant* getShade() = 0;
    virtual Plant* getCenter() = 0;
    virtual Plant* getBorder() = 0;
    virtual ~Garden() = default;
};

// -------------------------- 三个具体 Garden 类 --------------------------
class VeggieGarden : public Garden {
public:
    Plant* getShade() override { return new Plant("Broccoli"); }
    Plant* getCenter() override { return new Plant("Corn"); }
    Plant* getBorder() override { return new Plant("Peas"); }
};

class AnnualGarden : public Garden {
public:
    Plant* getShade() override { return new Plant("Coleus"); }
    Plant* getCenter() override { return new Plant("Marigold"); }
    Plant* getBorder() override { return new Plant("Alyssum"); }
};

class PerennialGarden : public Garden {
public:
    Plant* getShade() override { return new Plant("Astilbe"); }
    Plant* getCenter() override { return new Plant("Dicentrum"); }
    Plant* getBorder() override { return new Plant("Sedum"); }
};

// -------------------------- 前向声明 Gardener --------------------------
class Gardener;

// -------------------------- Dbutton 抽象基类 --------------------------
class Dbutton : public QPushButton {
    Q_OBJECT
public:
    Dbutton(QWidget* parent = nullptr) : QPushButton(parent) {
        connect(this, &QPushButton::clicked, this, &Dbutton::onClicked);
    }
    
    void setGarden(Gardener* gardener) { this->gardener = gardener; }
    
protected:
    virtual void comd() = 0;
    
private slots:
    void onClicked() { comd(); }
    
protected:
    Gardener* gardener = nullptr;
};

// -------------------------- 三个具体按钮 --------------------------
class CentralButton : public Dbutton {
public:
    CentralButton(QWidget* parent = nullptr) : Dbutton(parent) {}
protected:
    void comd() override;
};

class ShadeButton : public Dbutton {
public:
    ShadeButton(QWidget* parent = nullptr) : Dbutton(parent) {}
protected:
    void comd() override;
};

class BorderButton : public Dbutton {
public:
    BorderButton(QWidget* parent = nullptr) : Dbutton(parent) {}
protected:
    void comd() override;
};

// -------------------------- ChoiceButton (单选按钮) --------------------------
class ChoiceButton : public QRadioButton {
    Q_OBJECT
public:
    ChoiceButton(QWidget* parent, const QString& name, int index,
                 Garden* garden, Gardener* gardener, QButtonGroup* group)
        : QRadioButton(name, parent), name(name), index(index),
          garden(garden), gardener(gardener), group(group) {
        
        group->addButton(this, index);
        connect(this, &QRadioButton::toggled, this, &ChoiceButton::onToggled);
    }

private slots:
    void onToggled(bool checked) {
        if (checked) {
            comd();
        }
    }

    void comd();

private:
    QString name;
    int index;
    Garden* garden;
    Gardener* gardener;
    QButtonGroup* group;
};

// -------------------------- 自定义画布 Canvas --------------------------
class GardenCanvas : public QWidget {
    Q_OBJECT
public:
    GardenCanvas(QWidget* parent = nullptr) : QWidget(parent) {
        setFixedSize(200, 200);
        setStyleSheet("background-color: white;");
        drawBackground();
    }

    void clearCanvas() {
        shapes.clear();
        drawBackground();
        update();
    }

    void drawText(int x, int y, const QString& text) {
        shapes.append({Text, x, y, 0, 0, text});
        update();
    }

protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        for (const Shape& s : shapes) {
            if (s.type == Oval) {
                painter.setBrush(QBrush(Qt::lightGray));
                painter.setPen(Qt::black);
                painter.drawEllipse(s.x, s.y, s.w, s.h);
            } else if (s.type == Text) {
                painter.drawText(s.x, s.y, s.text);
            }
        }
    }

private:
    enum ShapeType { Oval, Text };
    struct Shape {
        ShapeType type;
        int x, y, w, h;
        QString text;
    };
    QVector<Shape> shapes;

    void drawBackground() {
        Shape oval;
        oval.type = Oval;
        oval.x = 20;
        oval.y = 20;
        oval.w = 80;
        oval.h = 80;
        shapes.append(oval);
    }
};

// -------------------------- Gardener 类 --------------------------
class Gardener {
public:
    Gardener() : garden(nullptr) {}

    void setGarden(Garden* g) {
        garden = g;
    }

    void clearCanvas() {
        if (canvas) {
            canvas->clearCanvas();
        }
    }

    void setCenter() {
        if (canvas && garden) {
            canvas->drawText(100, 120, garden->getCenter()->getName());
        }
    }

    void setBorder() {
        if (canvas && garden) {
            canvas->drawText(75, 180, garden->getBorder()->getName());
        }
    }

    void setShade() {
        if (canvas && garden) {
            canvas->drawText(60, 60, garden->getShade()->getName());
        }
    }

    void build() {
        QWidget* root = new QWidget();
        root->setWindowTitle("Garden planner");
        root->resize(450, 250);

        QGridLayout* mainLayout = new QGridLayout(root);

        // 左侧框架
        QWidget* lframe = new QWidget(root);
        QVBoxLayout* lframeLayout = new QVBoxLayout(lframe);
        
        // 花园类型分组框
        QGroupBox* lbframe = new QGroupBox("Garden type", lframe);
        QVBoxLayout* radioLayout = new QVBoxLayout(lbframe);
        
        QButtonGroup* groupv = new QButtonGroup(root);
        groupv->setExclusive(true);

        // 创建三个单选按钮
        VeggieGarden* vegGarden = new VeggieGarden();
        AnnualGarden* annGarden = new AnnualGarden();
        PerennialGarden* perGarden = new PerennialGarden();
        
        // 保存花园对象以便后续清理
        gardens.append(vegGarden);
        gardens.append(annGarden);
        gardens.append(perGarden);
        
        ChoiceButton* vegBtn = new ChoiceButton(lbframe, "Vegetable", 0, vegGarden, this, groupv);
        ChoiceButton* annBtn = new ChoiceButton(lbframe, "Annual", 1, annGarden, this, groupv);
        ChoiceButton* perBtn = new ChoiceButton(lbframe, "Perennial", 2, perGarden, this, groupv);
        
        radioLayout->addWidget(vegBtn);
        radioLayout->addWidget(annBtn);
        radioLayout->addWidget(perBtn);
        
        lframeLayout->addWidget(lbframe);
        
        // 退出按钮
        QPushButton* quitButton = new QPushButton("Quit", lframe);
        lframeLayout->addWidget(quitButton);
        lframeLayout->setAlignment(quitButton, Qt::AlignTop);
        lframeLayout->setContentsMargins(0, 50, 0, 0);  // pady=50
        
        lframe->setLayout(lframeLayout);

        // 右侧框架
        QWidget* rframe = new QWidget(root);
        QVBoxLayout* rframeLayout = new QVBoxLayout(rframe);
        
        // 画布
        canvas = new GardenCanvas(rframe);
        rframeLayout->addWidget(canvas);
        
        // 按钮框架
        QWidget* rf1 = new QWidget(rframe);
        QHBoxLayout* buttonLayout = new QHBoxLayout(rf1);
        
        CentralButton* centButton = new CentralButton(rf1);
        centButton->setText("Central");
        centButton->setGarden(this);
        
        BorderButton* bordButton = new BorderButton(rf1);
        bordButton->setText("Border");
        bordButton->setGarden(this);
        
        ShadeButton* shadeButton = new ShadeButton(rf1);
        shadeButton->setText("Shade");
        shadeButton->setGarden(this);
        
        buttonLayout->addWidget(centButton);
        buttonLayout->addWidget(bordButton);
        buttonLayout->addWidget(shadeButton);
        
        rf1->setLayout(buttonLayout);
        rframeLayout->addWidget(rf1);
        
        rframe->setLayout(rframeLayout);
        
        // 将左右框架添加到主布局
        mainLayout->addWidget(lframe, 0, 0);
        mainLayout->addWidget(rframe, 0, 1);
        
        root->setLayout(mainLayout);
        
        // 设置初始花园（默认 VeggieGarden）
        setGarden(vegGarden);
        clearCanvas();
        
        // 连接退出按钮
        QObject::connect(quitButton, &QPushButton::clicked, &QApplication::quit);
        
        root->show();
    }

    GardenCanvas* getCanvas() const { return canvas; }

    ~Gardener() {
        for (Garden* g : gardens) {
            delete g;
        }
    }

private:
    Garden* garden;
    GardenCanvas* canvas = nullptr;
    QVector<Garden*> gardens;
};

// -------------------------- Dbutton 派生类的 comd 实现 --------------------------
void CentralButton::comd() {
    if (gardener) gardener->setCenter();
}

void BorderButton::comd() {
    if (gardener) gardener->setBorder();
}

void ShadeButton::comd() {
    if (gardener) gardener->setShade();
}

void ChoiceButton::comd() {
    gardener->setGarden(garden);
    gardener->clearCanvas();
}

// -------------------------- main --------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    Gardener gardener;
    gardener.build();
    
    return app.exec();
}

#include "Gardening.moc"