#pragma once

#include "Visitor.hpp"
#include <vector>
#include <string>

class FileFindVisitor : public Visitor {
private:
    std::string filetype;
    std::vector<File*> found;

public:
    FileFindVisitor(const std::string& filetype);      // 指定.后面的文件后缀名，如".txt"
    ~FileFindVisitor() override;

    void visit(File* file) override;
    void visit(Directory* directory) override;

    const std::vector<File*>& getFoundFiles();     // 获取已经找到的文件
};

