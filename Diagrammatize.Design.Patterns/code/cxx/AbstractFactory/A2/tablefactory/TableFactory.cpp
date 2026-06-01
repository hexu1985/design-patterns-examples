#include "TableFactory.hpp"
#include "TableLink.hpp"
#include "TableTray.hpp"
#include "TablePage.hpp"

Link* TableFactory::createLink(const std::string& caption, const std::string& url) {
    return new TableLink(caption, url);
}

Tray* TableFactory::createTray(const std::string& caption) {
    return new TableTray(caption);
}

Page* TableFactory::createPage(const std::string& title, const std::string& author) {
    return new TablePage(title, author);
}

static Factory* newTableFactory() {
    return new TableFactory();
}

//static FactoryRegister factory("TableFactory", &newTableFactory);
REGISTER_FACTORY(TableFactory, &newTableFactory);
