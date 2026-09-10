#include "Host.hpp"

int main() {
    Host host(10000);
    try {
        std::cout << "execute BEGIN" << std::endl;
        host.execute();
    } catch (const TimeoutException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
