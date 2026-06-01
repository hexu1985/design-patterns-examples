#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>

#include "turtle/TurtleCanvas.hpp"
#include "language/InterpreterFacade.hpp"

class Widget : public QMainWindow {
    Q_OBJECT
public:
    Widget(const QString& title, QWidget* parent = nullptr)
        : QMainWindow(parent)
    {
        setWindowTitle(title);

        // 创建组件
        canvas_ = new TurtleCanvas(400, 400, this);
        facade_ = std::make_unique<InterpreterFacade>(canvas_);
        programTextField_ = new QLineEdit(this);

        // 设置初始程序文本
        programTextField_->setText("program repeat 3 go right go left end end");

        // 设置执行器
        canvas_->setExecutor(facade_.get());

        // 连接信号槽
        connect(programTextField_, &QLineEdit::returnPressed,
                this, &Widget::onProgramTextChanged);

        // 设置布局
        QWidget* centralWidget = new QWidget(this);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);
        layout->addWidget(programTextField_);
        layout->addWidget(canvas_);

        setCentralWidget(centralWidget);

        // 调整窗口大小以适应内容
        resize(400, 450);

        // 解析并执行
        parseAndExecute();
    }

    ~Widget() {}

protected:
    void closeEvent(QCloseEvent* event) override
    {
        // 处理窗口关闭事件
        event->accept();
        QApplication::quit();
    }

private slots:
    void onProgramTextChanged()
    {
        parseAndExecute();
    }

private:
    void parseAndExecute()
    {
        QString programText = programTextField_->text();
        qDebug() << "programText =" << programText;

        try {
            facade_->parse(programText.toStdString());
            canvas_->repaint();  // 触发重绘
        } catch (const std::exception& e) {
            qDebug() << "Parse error:" << e.what();
            // 可以选择显示错误消息
            // QMessageBox::warning(this, "Parse Error", QString("Error parsing program: ") + e.what());
        }
    }
    
    TurtleCanvas* canvas_;
    std::unique_ptr<InterpreterFacade> facade_;
    QLineEdit* programTextField_;
};

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Widget mainWindow("Interpreter Pattern Sample");
    mainWindow.show();

    return app.exec();
}

#include "main.moc"
