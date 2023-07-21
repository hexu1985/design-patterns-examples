#include "Trouble.hpp"
#include "Support.hpp"
#include "NoSupport.hpp"
#include "LimitSupport.hpp"
#include "SpecialSupport.hpp"
#include "OddSupport.hpp"

int main(int argc, char *argv[]) {
    Support* alice   = new NoSupport("Alice");
    Support* bob     = new LimitSupport("Bob", 100);
    Support* charlie = new SpecialSupport("Charlie", 429);
    Support* diana   = new LimitSupport("Diana", 200);
    Support* elmo    = new OddSupport("Elmo");
    Support* fred    = new LimitSupport("Fred", 300);
    // 形成职责链
    alice->setNext(bob)->setNext(charlie)->setNext(diana)->setNext(elmo)->setNext(fred);
    // 制造各种问题
    for (int i = 0; i < 500; i += 33) {
        alice->support(new Trouble(i));
    }
    return 0;
}
