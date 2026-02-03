#include "Namer.hpp"
#include <QStringList>

FirstFirst::FirstFirst(const QString& namestring) {
    int i = namestring.indexOf(" ");  // 查找名字之间的空格
    if (i > 0) {
        QStringList names = namestring.split(" ");
        first = names[0];
        if (names.size() > 1) {
            last = names[1];
        }
    } else {
        last = namestring;
        first = "";
    }
}

LastFirst::LastFirst(const QString& namestring) {
    int i = namestring.indexOf(",");  // 查找名字之间的逗号
    if (i > 0) {
        QStringList names = namestring.split(",");
        last = names[0].trimmed();
        if (names.size() > 1) {
            first = names[1].trimmed();
        }
    } else {
        last = namestring;
        first = "";
    }
}

NamerFactory::NamerFactory(const QString& namestring) : name(namestring) {}

Namer* NamerFactory::getNamer() {
    int i = name.indexOf(",");  // 如果找到逗号
    if (i > 0) {
        return new LastFirst(name);  // 获取 LastFirst 类
    } else {
        return new FirstFirst(name);  // 否则获取 FirstFirst 类
    }
}
