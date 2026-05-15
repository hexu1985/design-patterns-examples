#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class Builder : public QObject {
    Q_OBJECT
public:
    void build() {
        // 创建主窗口
        root = new QWidget();
        root->setWindowTitle("Addition");
        root->setFixedSize(350, 200);

        QGridLayout* layout = new QGridLayout(root);

        // 顶部提示标签
        QLabel* topLabel = new QLabel("Enter numbers to add", root);
        topLabel->setAlignment(Qt::AlignLeft);
        topLabel->setStyleSheet("QLabel { color: blue; padding: 10px 20px; }");
        layout->addWidget(topLabel, 0, 0, 1, 2);

        // 第一行：x 标签 + 输入框
        QLabel* xLabel = new QLabel("x=", root);
        xLabel->setStyleSheet("QLabel { color: blue; }");
        layout->addWidget(xLabel, 1, 0);

        xEntry = new QLineEdit(root);
        layout->addWidget(xEntry, 1, 1);
        layout->setColumnMinimumWidth(1, 10); // 模拟 padx=10

        // 第二行：y 标签 + 输入框
        QLabel* yLabel = new QLabel("y=", root);
        yLabel->setStyleSheet("QLabel { color: blue; }");
        layout->addWidget(yLabel, 2, 0);

        yEntry = new QLineEdit(root);
        layout->addWidget(yEntry, 2, 1);
        layout->setColumnMinimumWidth(1, 10); // 同样 padx 效果

        // OK 按钮
        okButton = new QPushButton("OK", root);
        layout->addWidget(okButton, 3, 0, 1, 2);
        QObject::connect(okButton, &QPushButton::clicked, this, &Builder::getSum);

        // 结果显示标签
        cLabel = new QLabel("sum", root);
        cLabel->setStyleSheet("QLabel { color: blue; }");
        layout->addWidget(cLabel, 4, 0, 1, 2);

        root->setLayout(layout);
        root->show();
    }

private slots:
    void getSum() {
        bool okX, okY;
        double xval = xEntry->text().toDouble(&okX);
        double yval = yEntry->text().toDouble(&okY);

        if (!okX || !okY) {
            QMessageBox::critical(root, "Conversion error", "Not numbers");
        } else {
            double sum = xval + yval;
            cLabel->setText("Sum = " + QString::number(sum));
        }
    }

private:
    QWidget* root = nullptr;
    QLineEdit* xEntry = nullptr;
    QLineEdit* yEntry = nullptr;
    QPushButton* okButton = nullptr;
    QLabel* cLabel = nullptr;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Builder bldr;
    bldr.build();      // 构建并显示窗口
    return app.exec(); // 主循环
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "Simplemath.moc"