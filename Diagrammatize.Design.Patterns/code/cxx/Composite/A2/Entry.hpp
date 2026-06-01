#pragma once

#include <string>
#include <iosfwd>

class Entry {
protected:
    Entry* parent = nullptr;

public:
    virtual ~Entry();
    virtual std::string getName() const = 0;      // 获取名字
    virtual int getSize() const = 0;              // 获取大小
    virtual Entry* add(Entry* entry);       // 加入目录条目

    void printList() const;                       // 为一览加上前缀并显示目录条目一览

    std::string toString() const;                 // 显示代表类的文字
    
    std::string getFullName() const;

protected:
    virtual void printList(const std::string& prefix) const = 0;               // 为一览加上前缀

    friend class File;
    friend class Directory;
};

std::ostream& operator<<(std::ostream&, const Entry&);
