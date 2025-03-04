#include <vector>
#include <string>

#include "SortAndPrint.hpp"
#include "QuickSorter.hpp"

int main() {
    std::vector<std::string> data = {
        "Dumpty", "Bowman", "Carroll", "Elfland", "Alice",
    };

    SortAndPrint<std::string, QuickSorter> sap(data, QuickSorter{});
    sap.execute();

    return 0;
}
