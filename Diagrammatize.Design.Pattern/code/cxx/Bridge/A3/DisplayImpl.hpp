#pragma once

class DisplayImpl {
public:
    virtual ~DisplayImpl();
    virtual void rawOpen() = 0;
    virtual void rawPrint() = 0;
    virtual void rawClose() = 0;
};
