#pragma once

#include <functional>

#include "Link.hpp"
#include "Tray.hpp"
#include "Page.hpp"

class Factory {
public:
    static Factory* getFactory(const std::string& classname);

    virtual ~Factory();
    virtual Link* createLink(const std::string& caption, const std::string& url) = 0;
    virtual Tray* createTray(const std::string& caption) = 0;
    virtual Page* createPage(const std::string& title, const std::string& author) = 0;

    Page* createYahooPage() {
        Link* link = createLink("Yahoo!", "http://www.yahoo.com/");
        Page* page = createPage("Yahoo!", "Yahoo!");
        page->add(link);
        return page;
    }
};

class FactoryRegister {
public:
    FactoryRegister(const std::string& classname, std::function<Factory*()> newFactory);
};

#define REGISTER_FACTORY(classname, newFactory) \
    static FactoryRegister factory_register_local(#classname, newFactory)
