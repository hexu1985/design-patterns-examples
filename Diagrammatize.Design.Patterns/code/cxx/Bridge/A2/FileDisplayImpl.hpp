#pragma once

#include <string>
#include <fstream>

#include "DisplayImpl.hpp"

class FileDisplayImpl: public DisplayImpl {
private:
    std::string filename;
    std::ifstream reader;

public:
    FileDisplayImpl(const std::string& filename);

    void rawOpen() override;
    void rawPrint() override;
    void rawClose() override;
};
