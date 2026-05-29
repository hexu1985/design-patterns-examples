#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "Builder.hpp"

class FrameBuilder : public QMainWindow, public Builder {
    Q_OBJECT
public:
    FrameBuilder(QWidget *parent = nullptr);
    ~FrameBuilder() override;

    // Builder 接口实现
    void makeTitle(const std::string& title) override;
    void makeString(const std::string& str) override;
    void makeItems(const std::vector<std::string>& items) override;
    void close() override;
    
    QMainWindow* getResult();

private slots:
    void onButtonClicked();

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
};

