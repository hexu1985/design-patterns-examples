#pragma once

#include <QWidget>
#include <vector>

class Checkbox;

// Create the window, checkboxes and Order button
class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);
    virtual ~Widget();

private:
    std::vector<Checkbox*> m_boxes;
};
