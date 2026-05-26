#pragma once

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include "language/ExecutorFactory.hpp"
#include "language/Executor.hpp"

class TurtleCanvas : public QWidget, public ExecutorFactory {
    Q_OBJECT
public:
    static const int UNIT_LENGTH = 30;
    static const int DIRECTION_UP = 0;
    static const int DIRECTION_RIGHT = 3;
    static const int DIRECTION_DOWN = 6;
    static const int DIRECTION_LEFT = 9;
    static const int RELATIVE_DIRECTION_RIGHT = 3;
    static const int RELATIVE_DIRECTION_LEFT = -3;
    static const int RADIUS = 3;

    explicit TurtleCanvas(int width, int height, QWidget* parent = nullptr);
    ~TurtleCanvas();

    void setExecutor(Executor* executor);
    void setRelativeDirection(int relativeDirection);
    void setDirection(int direction);
    void go(int length);

    std::unique_ptr<Executor> createExecutor(const std::string& name) override;
    void initialize();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int direction_;
    QPoint position_;
    Executor* executor_;
};

