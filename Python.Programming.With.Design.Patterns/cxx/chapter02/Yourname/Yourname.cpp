#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Builder : public QObject {
    Q_OBJECT    
public:
    void build() {
        root = new QWidget();
        root->setWindowTitle("Greeting");
        root->setFixedSize(300, 200);

        QVBoxLayout* layout = new QVBoxLayout(root);

        // 顶部提示标签
        QLabel* topLabel = new QLabel("What is your name?", root);
        topLabel->setAlignment(Qt::AlignLeft);
        topLabel->setStyleSheet("QLabel { color: blue; padding: 10px 20px; }");
        layout->addWidget(topLabel);

        // 输入框
        nmEntry = new QLineEdit(root);
        layout->addWidget(nmEntry);

        // OK 按钮
        okButton = new QPushButton("OK", root);
        layout->addWidget(okButton);
        QObject::connect(okButton, &QPushButton::clicked, this, &Builder::getName);

        // 结果显示标签
        cLabel = new QLabel("name", root);
        cLabel->setStyleSheet("QLabel { color: blue; }");
        layout->addWidget(cLabel);

        root->setLayout(layout);
        root->show();
    }

private slots:
    void getName() {
        QString newName = nmEntry->text();
        cLabel->setText("Hi " + newName + " boy!");
    }

private:
    QWidget* root = nullptr;
    QLineEdit* nmEntry = nullptr;
    QPushButton* okButton = nullptr;
    QLabel* cLabel = nullptr;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Builder bldr;
    bldr.build();
    return app.exec();
}

// 需要包含 moc 生成的代码（因为 Q_OBJECT 在 cpp 文件中）
#include "Yourname.moc"