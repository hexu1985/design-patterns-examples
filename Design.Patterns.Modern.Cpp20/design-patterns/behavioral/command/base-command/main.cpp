#include <iostream>
#include <vector>

using namespace std;

struct BankAccount {
  int balance{0};
  int overdraft_limit{-500};

  void deposit(int amount) {
    balance += amount;
    cout << "deposited " << amount << ", balance is now " << balance << endl;
  }

  void withdraw(int amount) {
    if (balance - amount >= overdraft_limit) {
      balance -= amount;
      cout << "withdrew " << amount << ", balance is now " << balance << endl;
    }
  }

  friend ostream &operator<<(ostream &os, const BankAccount &obj) {
    return os << "balance: " << obj.balance;
  }
};

/**
 * Command abstract class
 */
struct Command {
  virtual void call() = 0;
};

struct BankAccountCommand : Command {
  BankAccount &account;
  enum Action { deposit, withdraw } action;
  int amount;

  BankAccountCommand(BankAccount &account, Action action, int amount)
      : account(account), action(action), amount(amount) {}

  void call() override {
    switch (action) {
    case deposit:
      account.deposit(amount);
      break;
    case withdraw:
      account.withdraw(amount);
      break;
    }
  }
};

int main() {
  BankAccount ba;
  vector<BankAccountCommand> commands{
      BankAccountCommand(ba, BankAccountCommand::deposit, 100),
      BankAccountCommand(ba, BankAccountCommand::withdraw, 20),
  };

  cout << ba << endl;

  for (auto &cmd : commands) {
    cmd.call();
  }

  cout << ba << endl;
}
