#include "Table.hpp"
#include "MakerThread.hpp"
#include "EaterThread.hpp"

int main() {
    Table table(3);  // 创建一个能放置 3 个蛋糕的桌子

    MakerThread maker1("MakerThread-1", table, 31415);
    MakerThread maker2("MakerThread-2", table, 92653);
    MakerThread maker3("MakerThread-3", table, 58979);
    EaterThread eater1("EaterThread-1", table, 32384);
    EaterThread eater2("EaterThread-2", table, 62643);
    EaterThread eater3("EaterThread-3", table, 38327);

    maker1.start();
    maker2.start();
    maker3.start();
    eater1.start();
    eater2.start();
    eater3.start();

    return 0;
}
