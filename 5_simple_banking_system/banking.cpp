/**
 * Simple Banking System
 * 
 * This program simulates basic banking operations in a command line interface using C++.
 * It allows creating, depositing into, withdrawing from, and closing bank accounts.
 * The operations demonstrate the use of modern C++17 features such as std::optional and structured bindings.
 * 
 * Features:
 * - Open a bank account with an initial balance.
 * - Deposit money into a bank account.
 * - Withdraw money from a bank account.
 * - Show the current balance of a bank account.
 * - Close a bank account and optionally return the account details.
 */

#include <iostream>
#include <map>
#include <string>
#include <optional>

using namespace std;

class BankAccount {
private:
    int accountNumber;  // Unique identifier for the bank account
    double balance;     // Current balance of the bank account

public:
    // Constructor initializes account number and balance
    BankAccount(int accountNumber, double initialBalance)
        : accountNumber(accountNumber), balance(initialBalance) {}

    // Deposits the specified amount into the account
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << endl;
    }

    // Withdraws the specified amount from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Available balance: " << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << ". Remaining balance: " << balance << endl;
        }
    }

    // Returns the current balance of the account
    double getBalance() const {
        return balance;
    }

    // Returns the account number
    int getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    map<int, BankAccount> accounts;  // Stores all bank accounts using account numbers as keys

public:
    // Opens a new bank account with the given account number and initial balance
    void openAccount(int accountNumber, double initialBalance) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account already exists!" << endl;
        } else {
            accounts.emplace(accountNumber, BankAccount(accountNumber, initialBalance));
            cout << "Account " << accountNumber << " opened with balance " << initialBalance << endl;
        }
    }

    // Closes the bank account with the given account number and returns the final account details
    optional<BankAccount> closeAccount(int accountNumber) {
        if (auto it = accounts.find(accountNumber); it != accounts.end()) {
            auto account = move(it->second);
            accounts.erase(it);
            cout << "Account " << accountNumber << " closed." << endl;
            return account;
        } else {
            cout << "Account does not exist!" << endl;
            return nullopt;
        }
    }

    // Deposits the specified amount into the bank account with the given account number
    bool deposit(int accountNumber, double amount) {
        if (auto it = accounts.find(accountNumber); it != accounts.end()) {
            it->second.deposit(amount);
            return true;
        } else {
            cout << "Account does not exist!" << endl;
            return false;
        }
    }

    // Withdraws the specified amount from the bank account with the given account number
    bool withdraw(int accountNumber, double amount) {
        if (auto it = accounts.find(accountNumber); it != accounts.end()) {
            it->second.withdraw(amount);
            return true;
        } else {
            cout << "Account does not exist!" << endl;
            return false;
        }
    }

    // Shows the balance of the bank account with the given account number
    optional<double> showBalance(int accountNumber) {
        if (auto it = accounts.find(accountNumber); it != accounts.end()) {
            cout << "The balance of account " << accountNumber << " is " << it->second.getBalance() << endl;
            return it->second.getBalance();
        } else {
            cout << "Account does not exist!" << endl;
            return nullopt;
        }
    }
};

int main() {
    Bank myBank;
    myBank.openAccount(101, 500.0);
    myBank.deposit(101, 220.0);
    myBank.withdraw(101, 100.0);
    if (auto balance = myBank.showBalance(101); balance) {
        cout << "Current balance: " << *balance << endl;
    }
    myBank.closeAccount(101);

    return 0;
}
