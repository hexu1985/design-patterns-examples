#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QVBoxLayout>

// 自定义画布类，类似 tkinter.Canvas
class Canvas : public QWidget {
public:
    Canvas(QWidget* parent = nullptr) : QWidget(parent) {
    }

    // 记录一个矩形 (x, y, width, height)
    void addRectangle(int x, int y, int w, int h) {
        rectangles.append({x, y, w, h});
        update();  // 触发重绘
    }

protected:
    void paintEvent(QPaintEvent*) override {
        QPainter painter(this);
        painter.setBrush(Qt::NoBrush);      // 和 tkinter 默认空心矩形一致
        painter.setPen(Qt::black);

        for (const auto& rect : rectangles) {
            painter.drawRect(rect.x, rect.y, rect.w, rect.h);
        }
    }

private:
    struct Rect { int x, y, w, h; };
    QVector<Rect> rectangles;
};

// Rectangle 类：在画布上绘制矩形
class Rectangle {
public:
    Rectangle(Canvas* canvas) : canvas(canvas) {}

    void draw(int x, int y, int w, int h) {
        canvas->addRectangle(x, y, w, h);
    }

private:
    Canvas* canvas;
};

// Square 类：继承 Rectangle，绘制正方形
class Square : public Rectangle {
public:
    Square(Canvas* canvas) : Rectangle(canvas) {}

    void draw(int x, int y, int w) {
        Rectangle::draw(x, y, w, w);   // 宽高相同，即为正方形
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 主窗口（类似 tkinter.Tk）
    QWidget root;
    root.setWindowTitle("Canvas Demo");
    root.resize(400, 300);

    // 创建画布控件（类似 tkinter.Canvas）
    Canvas* canvas = new Canvas(&root);
    canvas->setGeometry(0, 0, root.width(), root.height());
    canvas->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 设置布局，使 canvas 随窗口拉伸（类似 pack(expand=1)）
    QVBoxLayout* layout = new QVBoxLayout(&root);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(canvas);
    root.setLayout(layout);

    // 创建 Rectangle 并绘制
    Rectangle rect1(canvas);
    rect1.draw(30, 10, 120, 80);     // 矩形

    // 创建 Square 并绘制
    Square square(canvas);
    square.draw(200, 50, 60);        // 正方形

    root.show();
    return app.exec();
}
