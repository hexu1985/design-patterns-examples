#include <vector>
#include <string>

#include "SortAndPrint.hpp"
#include "SelectionSorter.hpp"

int main() {
    std::vector<std::string> data = {
        "Dumpty", "Bowman", "Carroll", "Elfland", "Alice",
    };

    SortAndPrint<std::string, SelectionSorter> sap(data, SelectionSorter{});
    sap.execute();

    return 0;
}
