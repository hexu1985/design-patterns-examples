#include "ListFactory.hpp"
#include "ListLink.hpp"
#include "ListTray.hpp"
#include "ListPage.hpp"

Link* ListFactory::createLink(const std::string& caption, const std::string& url) {
    return new ListLink(caption, url);
}

Tray* ListFactory::createTray(const std::string& caption) {
    return new ListTray(caption);
}

Page* ListFactory::createPage(const std::string& title, const std::string& author) {
    return new ListPage(title, author);
}

static Factory* newListFactory() {
    return new ListFactory();
}

//static FactoryRegister factory("ListFactory", &newListFactory);
REGISTER_FACTORY(ListFactory, &newListFactory);
