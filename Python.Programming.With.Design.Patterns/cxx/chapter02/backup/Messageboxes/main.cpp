#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 显示警告消息框
    QMessageBox::warning(nullptr, "Warning", "file not found");

    // 显示错误消息框
    QMessageBox::critical(nullptr, "Error", "Division by zero");

    // 显示确认对话框 (OK/Cancel)
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Continue", "Go on?",
                                  QMessageBox::Ok | QMessageBox::Cancel);
    bool result = (reply == QMessageBox::Ok);

    // 显示是/否/取消对话框
    reply = QMessageBox::question(nullptr, "Really", "Want to go on?",
                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    bool yesSelected = (reply == QMessageBox::Yes);
    bool noSelected = (reply == QMessageBox::No);
    bool cancelSelected = (reply == QMessageBox::Cancel);

    // 打开单个文件
    QString fileName = QFileDialog::getOpenFileName(nullptr, 
                                                   "Open File", 
                                                   "", 
                                                   "TXT Files (*.txt)");
    qDebug() << fileName;

    // 打开多个文件
    QStringList fileNames = QFileDialog::getOpenFileNames(nullptr, 
                                                         "Open Files", 
                                                         "", 
                                                         "CPP Files (*.cpp)");
    qDebug() << fileNames;

    return 0;
}
