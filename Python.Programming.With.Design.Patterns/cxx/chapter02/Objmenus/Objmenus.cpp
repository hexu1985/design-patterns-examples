#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QDebug>

// ------------------------ 自定义画布（模拟 tkinter.Canvas）------------------------
class Canvas : public QWidget {
public:
    Canvas(QWidget* parent = nullptr) : QWidget(parent) {
        setMinimumSize(300, 200);
    }

    void addCircle(int x1, int y1, int x2, int y2, const QColor& fill = Qt::red) {
        shapes.append({Circle, x1, y1, x2, y2, fill});
        update();
    }

    void addRectangle(int x1, int y1, int x2, int y2, const QColor& fill = Qt::blue) {
        shapes.append({Rectangle, x1, y1, x2, y2, fill});
        update();
    }

protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        for (const Shape& s : shapes) {
            painter.setBrush(s.fillColor);
            painter.setPen(Qt::black);
            if (s.type == Circle) {
                painter.drawEllipse(QRect(s.x1, s.y1, s.x2 - s.x1, s.y2 - s.y1));
            } else if (s.type == Rectangle) {
                painter.drawRect(QRect(s.x1, s.y1, s.x2 - s.x1, s.y2 - s.y1));
            }
        }
    }

private:
    enum ShapeType { Circle, Rectangle };
    struct Shape {
        ShapeType type;
        int x1, y1, x2, y2;
        QColor fillColor;
    };
    QVector<Shape> shapes;
};

// ------------------------ 菜单栏（对应 tkinter Menu）------------------------
class Menubar : public QMenuBar {
public:
    Menubar(QMainWindow* root) : QMenuBar(root) {
        root->setMenuBar(this);
    }
};

// ------------------------ 抽象菜单命令 ------------------------
class Menucommand : public QObject {
    Q_OBJECT
public:
    Menucommand(QMainWindow* root, const QString& label)
        : root(root), label(label) {}

    QString getLabel() const { return label; }
    virtual void comd() {}

protected:
    QMainWindow* root;
    QString label;
};

// ------------------------ Open 命令 ------------------------
class Opencommand : public Menucommand {
public:
    Opencommand(QMainWindow* root, const QString& label)
        : Menucommand(root, label) {}

    void comd() override {
        QString fname = QFileDialog::getOpenFileName(root, "Select file");
        if (!fname.trimmed().isEmpty()) {
            QStringList parts = fname.split("/");
            if (!parts.isEmpty())
                fname = parts.last();
            root->setWindowTitle(fname);
        }
    }
};

// ------------------------ Quit 命令 ------------------------
class Quitcommand : public Menucommand {
public:
    Quitcommand(QMainWindow* root, const QString& label)
        : Menucommand(root, label) {}

    void comd() override {
        QApplication::quit();
    }
};

// ------------------------ DrawCircle 命令 ------------------------
class Drawcircle : public Menucommand {
public:
    Drawcircle(QMainWindow* root, Canvas* canvas, const QString& label)
        : Menucommand(root, label), canvas(canvas) {}

    void comd() override {
        canvas->addCircle(130, 40, 200, 110, Qt::red);
    }

private:
    Canvas* canvas;
};

// ------------------------ DrawSquare 命令 ------------------------
class Drawsquare : public Menucommand {
public:
    Drawsquare(QMainWindow* root, Canvas* canvas, const QString& label)
        : Menucommand(root, label), canvas(canvas) {}

    void comd() override {
        canvas->addRectangle(10, 80, 110, 180, Qt::blue);
    }

private:
    Canvas* canvas;
};

// ------------------------ 顶级菜单（File / Draw）--------------------
class TopMenu {
public:
    TopMenu(QMainWindow* root, const QString& label, Menubar* menubar) {
        fmenu = new QMenu(label, menubar);
        menubar->addMenu(fmenu);
    }

    void addMenuitem(Menucommand* mcomd) {
        QAction* action = fmenu->addAction(mcomd->getLabel());
        // 连接 triggered 信号到命令对象的 comd 槽（注意：comd 需为槽函数）
        QObject::connect(action, &QAction::triggered, mcomd, &Menucommand::comd);
    }

    void addSeparator() {
        fmenu->addSeparator();
    }

private:
    QMenu* fmenu;
};

// ------------------------ 初始化 UI ------------------------
void InitUI(QMainWindow* root) {
    root->setWindowTitle("Menu demo");
    root->setFixedSize(300, 200);

    // 创建中央画布
    Canvas* canvas = new Canvas(root);
    root->setCentralWidget(canvas);

    // 创建菜单栏
    Menubar* menubar = new Menubar(root);

    // 创建 File 菜单及其子项
    TopMenu filemenu(root, "File", menubar);
    filemenu.addMenuitem(new Menucommand(root, "New"));  // 空命令，直接传基类指针，comd 为空实现
    filemenu.addMenuitem(new Opencommand(root, "Open"));
    filemenu.addSeparator();
    filemenu.addMenuitem(new Quitcommand(root, "Quit"));

    // 创建 Draw 菜单及其子项
    TopMenu drawmenu(root, "Draw", menubar);
    drawmenu.addMenuitem(new Drawcircle(root, canvas, "Circle"));
    drawmenu.addMenuitem(new Drawsquare(root, canvas, "Square"));
}

// ------------------------ main ------------------------
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QMainWindow root;
    InitUI(&root);
    root.show();
    return app.exec();
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "Objmenus.moc"
