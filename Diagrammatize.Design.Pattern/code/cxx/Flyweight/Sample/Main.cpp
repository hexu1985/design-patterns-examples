#include "BigString.hpp"

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Usage: %s digits\n", argv[0]);
        printf("Example: %s 1212123\n", argv[0]);
        exit(0);
    }

    BigString bs{argv[1]};
    bs.print();
}

