#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  // Qt 应用必须，即使不需要窗口

    // 警告框
    QMessageBox::warning(nullptr, "Warning", "file not found");

    // 错误框
    QMessageBox::critical(nullptr, "Error", "Division by zero");

    // askokcancel: 返回 QMessageBox::Ok 或 QMessageBox::Cancel
    int result = QMessageBox::question(nullptr, "Continue", "Go on?",
                                       QMessageBox::Ok | QMessageBox::Cancel);
    if (result == QMessageBox::Ok) {
        qDebug() << "User clicked OK";
    } else {
        qDebug() << "User clicked Cancel";
    }

    // askyesnocancel: 返回 Yes / No / Cancel
    int result2 = QMessageBox::question(nullptr, "Really", "Want to go on?",
                                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    qDebug() << "Result:" << result2;  // 实际比较时用 QMessageBox::Yes 等

    // 选择单个文件，返回 QString
    QString fname = QFileDialog::getOpenFileName(nullptr, "Open File", "",
                                                 "TXT Files (*.txt)");
    qDebug() << fname;

    // 选择多个文件，返回 QStringList
    QStringList fnames = QFileDialog::getOpenFileNames(nullptr, "Select Python files", "",
                                                       "CPP Files (*.cpp)");
    qDebug() << fnames;

    return 0;
}
