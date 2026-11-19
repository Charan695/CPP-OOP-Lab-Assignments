#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Base class for banking-related exceptions.
class BankingException : public runtime_error {
public:
    explicit BankingException(const string& message) : runtime_error(message) {}
};

class InsufficientFundsException : public BankingException {
public:
    InsufficientFundsException()
        : BankingException("Insufficient account balance.") {}
};

class InvalidAmountException : public BankingException {
public:
    InvalidAmountException()
        : BankingException("Transaction amount must be positive.") {}
};

class Account {
private:
    string holder;
    double balance;
public:
    Account(const string& name, double openingBalance)
        : holder(name), balance(openingBalance) {}

    void deposit(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawal successful.\n";
    }

    void display() const {
        cout << holder << " | Balance: Rs. " << balance << '\n';
    }
};

int main() {
    Account account("Riya", 5000.0);
    account.display();

    try {
        account.deposit(1500.0);
        account.withdraw(2000.0);
        account.withdraw(10000.0); // Deliberately triggers insufficient funds.
    } catch (const InsufficientFundsException& error) {
        cout << "Insufficient funds: " << error.what() << '\n';
    } catch (const InvalidAmountException& error) {
        cout << "Invalid amount: " << error.what() << '\n';
    } catch (const BankingException& error) {
        cout << "Banking error: " << error.what() << '\n';
    }

    cout << "\nFinal account details:\n";
    account.display();
    return 0;
}
