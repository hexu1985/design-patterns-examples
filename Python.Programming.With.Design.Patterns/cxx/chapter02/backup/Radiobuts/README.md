以下是等效的 C++ Qt 代码：

```cpp
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class NameWindow : public QWidget {
    Q_OBJECT

private:
    QLineEdit *nmEntry;
    QLabel *cLabel;

public:
    NameWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // 创建主布局
        QVBoxLayout *layout = new QVBoxLayout(this);
        
        // 顶部标签
        QLabel *questionLabel = new QLabel("What is your name?");
        questionLabel->setStyleSheet("color: blue;");
        questionLabel->setContentsMargins(20, 10, 20, 10); // padx=20, pady=10
        layout->addWidget(questionLabel);
        
        // 创建输入字段
        nmEntry = new QLineEdit();
        layout->addWidget(nmEntry);
        
        // OK 按钮
        QPushButton *okButton = new QPushButton("OK");
        layout->addWidget(okButton);
        
        // 这是文本会改变的标签
        cLabel = new QLabel("name");
        cLabel->setStyleSheet("color: blue;");
        layout->addWidget(cLabel);
        
        // 连接按钮点击信号到槽函数
        connect(okButton, &QPushButton::clicked, this, &NameWindow::getName);
    }

private slots:
    void getName() {
        QString newName = nmEntry->text();
        cLabel->setText("Hi " + newName + " boy!");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    NameWindow window;
    window.setWindowTitle("Name App");
    window.resize(300, 200);
    window.show();
    
    return app.exec();
}

#include "main.moc"  // 对于单个文件项目，需要包含 moc 文件
```

主要对应关系：

1. **导入模块**：
   - Python tkinter → C++ Qt 头文件

2. **类结构**：
   - `Builder` 类 → `NameWindow` 类（继承自 `QWidget`）

3. **布局**：
   - `pack()` → `QVBoxLayout`

4. **组件**：
   - `Label` → `QLabel`
   - `Entry` → `QLineEdit`
   - `Button` → `QPushButton`

5. **样式**：
   - `fg='blue'` → `setStyleSheet("color: blue;")`
   - `padx=20, pady=10` → `setContentsMargins(20, 10, 20, 10)`

6. **事件处理**：
   - `command=self.getName` → `connect(okButton, &QPushButton::clicked, this, &NameWindow::getName)`

7. **主循环**：
   - `mainloop()` → `app.exec()`

这个 Qt 应用程序会创建一个窗口，功能与原始的 Python tkinter 代码完全相同：用户输入姓名，点击 OK 按钮后，下方的标签会显示 "Hi [姓名] boy!"。
