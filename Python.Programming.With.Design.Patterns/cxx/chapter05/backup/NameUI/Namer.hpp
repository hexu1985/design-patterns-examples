#pragma once

#include <QString>

// 基类 Namer
class Namer {
public:
    QString last;
    QString first;
    
    virtual ~Namer() {}
};

// First <space> Last 的派生类
class FirstFirst : public Namer {
public:
    FirstFirst(const QString& namestring);
};

// Last <comma> First 的派生类
class LastFirst : public Namer {
public:
    LastFirst(const QString& namestring);
};

// NameFactory 根据逗号是否存在返回相应的 Namer 实例
class NamerFactory {
private:
    QString name;
    
public:
    NamerFactory(const QString& namestring);
    Namer* getNamer();
};

