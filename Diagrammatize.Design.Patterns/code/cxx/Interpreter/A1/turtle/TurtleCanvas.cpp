// TurtleCanvas.cpp
#include "TurtleCanvas.hpp"
#include "language/ExecuteException.hpp"
#include <QDebug>

class GoExecutor;
class DirectionExecutor;

const int TurtleCanvas::UNIT_LENGTH;
const int TurtleCanvas::DIRECTION_UP;
const int TurtleCanvas::DIRECTION_RIGHT;
const int TurtleCanvas::DIRECTION_DOWN;
const int TurtleCanvas::DIRECTION_LEFT;
const int TurtleCanvas::RELATIVE_DIRECTION_RIGHT;
const int TurtleCanvas::RELATIVE_DIRECTION_LEFT;
const int TurtleCanvas::RADIUS;

// 前向声明内部类
class TurtleExecutor : public Executor
{
protected:
    TurtleCanvas* canvas_;
    
public:
    TurtleExecutor(TurtleCanvas* canvas) : canvas_(canvas) {}
    virtual ~TurtleExecutor() {}
};

class GoExecutor : public TurtleExecutor
{
public:
    GoExecutor(TurtleCanvas* canvas) : TurtleExecutor(canvas) {}
    
    void execute() override {
        canvas_->go(TurtleCanvas::UNIT_LENGTH);
    }
};

class DirectionExecutor : public TurtleExecutor
{
private:
    int relativeDirection;
    
public:
    DirectionExecutor(TurtleCanvas* canvas, int relativeDirection) 
        : TurtleExecutor(canvas), relativeDirection(relativeDirection) {}
    
    void execute() override {
        canvas_->setRelativeDirection(relativeDirection);
    }
};

// TurtleCanvas 实现
TurtleCanvas::TurtleCanvas(int width, int height, QWidget* parent)
    : QWidget(parent), direction_(0), executor_(nullptr)
{
    setFixedSize(width, height);
    initialize();
}

TurtleCanvas::~TurtleCanvas()
{
}

void TurtleCanvas::setExecutor(Executor* executor)
{
    executor_ = executor;
}

void TurtleCanvas::setRelativeDirection(int relativeDirection)
{
    setDirection(direction_ + relativeDirection);
}

void TurtleCanvas::setDirection(int direction)
{
    if (direction < 0) {
        direction = 12 - (-direction) % 12;
    } else {
        direction = direction % 12;
    }
    direction_ = direction % 12;
}

void TurtleCanvas::go(int length)
{
    int newx = position_.x();
    int newy = position_.y();
    
    switch (direction_) {
    case DIRECTION_UP:
        newy -= length;
        break;
    case DIRECTION_RIGHT:
        newx += length;
        break;
    case DIRECTION_DOWN:
        newy += length;
        break;
    case DIRECTION_LEFT:
        newx -= length;
        break;
    default:
        break;
    }
    
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    
    // 画线
    painter.drawLine(position_.x(), position_.y(), newx, newy);
    // 画圆点
    painter.drawEllipse(QPoint(newx, newy), RADIUS, RADIUS);
    
    position_.setX(newx);
    position_.setY(newy);
}

std::unique_ptr<Executor> TurtleCanvas::createExecutor(const std::string& name)
{
    if (name == "go") {
        return std::make_unique<GoExecutor>(this);
    } else if (name == "right") {
        return std::make_unique<DirectionExecutor>(this, RELATIVE_DIRECTION_RIGHT);
    } else if (name == "left") {
        return std::make_unique<DirectionExecutor>(this, RELATIVE_DIRECTION_LEFT);
    } else {
        return nullptr;
    }
}

void TurtleCanvas::initialize()
{
    position_ = QPoint(width() / 2, height() / 2);
    direction_ = 0;
    
    QPalette pal = palette();
    pal.setColor(QPalette::Foreground, Qt::red);
    pal.setColor(QPalette::Background, Qt::white);
    setPalette(pal);
    setAutoFillBackground(true);
    
    update(); // 清空画布
}

void TurtleCanvas::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    initialize();
    
    if (executor_ != nullptr) {
        try {
            executor_->execute();
        } catch (const ExecuteException& e) {
            // 处理异常，可以添加日志输出
            qDebug() << "ExecuteException caught:" << e.what();
        }
    }
}
