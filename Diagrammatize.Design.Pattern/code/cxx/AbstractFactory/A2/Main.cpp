#include <stdlib.h>
#include <stdio.h>
#include "factory/Factory.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s class.name.of.ConcreteFactory\n", argv[0]);
        printf("Example 1: %s ListFactory\n", argv[0]);
        printf("Example 2: %s TableFactory\n", argv[0]);
        exit(0);
    }

    Factory* factory = Factory::getFactory(argv[1]);
    Page* page = factory->createYahooPage();
    page->output();

    return 0;
}
