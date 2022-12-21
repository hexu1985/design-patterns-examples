#pragma once

#include <string>
#include <vector>

class Builder {
private:
    bool initialized = false;

public:
    virtual ~Builder();

    void makeTitle(const std::string& title) {
        if (!initialized) {
            buildTitle(title);
            initialized = true;
        }
    }

    void makeString(const std::string& str) {
        if (initialized) {
            buildString(str);
        }
    }

    void makeItems(const std::vector<std::string>& items) {
        if (initialized) {
            buildItems(items);
        }
    }

    void close() {
        if (initialized) {
            buildDone();
        }
    }

protected:
    virtual void buildTitle(const std::string& title) = 0;
    virtual void buildString(const std::string& str) = 0;
    virtual void buildItems(const std::vector<std::string>& items) = 0;
    virtual void buildDone() = 0;
};
