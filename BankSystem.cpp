#include "BankSystem.h"
#include <iostream>
#include <iomanip>

// Customer implementation
Customer::Customer(const std::string& name, const std::string& address, const std::string& phone, const std::string& customer_type)
    : name(name), address(address), phone(phone), customer_type(customer_type) {}

std::string Customer::get_name() const {
    return name;
}

std::string Customer::get_customer_type() const {
    return customer_type;
}

// Account implementation
Account::Account(const std::string& account_type) : balance(0.0), account_type(account_type) {}

void Account::deposit(double amount, const std::string& date) {
    balance += amount;
    transactions.push_back("DEP  " + date + "  $ " + std::to_string(amount) + "  $ " + std::to_string(balance));
}

void Account::withdraw(double amount, const std::string& date) {
    if (balance >= amount) {
        balance -= amount;
        transactions.push_back("WD   " + date + "  $ " + std::to_string(amount) + "  $ " + std::to_string(balance));
    } else {
        std::cout << "Insufficient balance!\n";
    }
}

double Account::get_balance() const {
    return balance;
}

std::vector<std::string> Account::get_transactions() const {
    return transactions;
}

// Bank implementation
void Bank::create_customer(const std::string& customer_type) {
    customers.push_back(std::make_unique<Customer>("John Doe", "123 Main St", "555-1234", customer_type));
}

Account* Bank::create_account(const std::string& account_type) {
    accounts.push_back(std::make_unique<Account>(account_type));
    return accounts.back().get();
}

Account* Bank::get_account(int account_number) {
    if (account_number >= 0 && account_number < accounts.size()) {
        return accounts[account_number].get();
    }
    return nullptr;
}

Customer* Bank::get_customer(int account_number) {
    if (account_number >= 0 && account_number < customers.size()) {
        return customers[account_number].get();
    }
    return nullptr;
}

int Bank::get_account_count() const {
    return accounts.size();
}
