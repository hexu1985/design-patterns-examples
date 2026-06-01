#pragma once

#include "DisplayImpl.hpp"

class CharDisplayImpl: public DisplayImpl {
private:
    char head;
    char body;
    char foot;

public:
    CharDisplayImpl(char head, char body, char foot);

    void rawOpen() override;
    void rawPrint() override;
    void rawClose() override;
};

