#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

protected:
    string holderName;

public:
    BankAccount(const string& number, const string& name, double openingBalance)
        : accountNumber(number), balance(openingBalance), holderName(name) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful.\n";
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Withdrawal rejected.\n";
            return false;
        }
        balance -= amount;
        cout << "Withdrawal successful.\n";
        return true;
    }

    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }

    void display() const {
        cout << "Account number: " << accountNumber
             << "\nAccount holder: " << holderName
             << "\nBalance: Rs. " << balance << '\n';
    }

    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& number, const string& name,
                   double openingBalance, double rate)
        : BankAccount(number, name, openingBalance), interestRate(rate) {}

    void showInterestRate() const {
        cout << "Interest rate for " << holderName << ": "
             << interestRate << "% per annum\n";
    }
};

int main() {
    SavingsAccount account("SB1001", "Aarav", 5000.0, 4.0);
    cout << "===== Bank Account =====\n";
    account.display();
    account.deposit(1500.0);
    account.withdraw(1000.0);
    account.showInterestRate();
    cout << "\nUpdated details:\n";
    account.display();
    return 0;
}
