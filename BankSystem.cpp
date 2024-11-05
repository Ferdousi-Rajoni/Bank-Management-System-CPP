// BankSystem.cpp
// Module: Bank Account Management System
// Author: Jannatul Ferdousi Rajoni
// Date: 05/11/24
// Purpose: Implementation of the Customer, Account, and Bank classes.
// This module provides functionalities for managing customers and their accounts,
// enabling operations such as deposits, withdrawals, and transaction tracking
// for each account.




#include "BankSystem.h"
#include <iostream>
#include <iomanip>

// Customer implementation

// Constructor for Customer class
// Parameters:
// - name: The name of the customer
// - address: The address of the customer
// - phone: The phone number of the customer
// - customer_type: The type of the customer (e.g., regular, premium)
Customer::Customer(const std::string& name, const std::string& address, const std::string& phone, const std::string& customer_type)
    : name(name), address(address), phone(phone), customer_type(customer_type) {}

// Getter for customer name
// Returns: The name of the customer
std::string Customer::get_name() const {
    return name;
}

// Getter for customer type
// Returns: The type of the customer
std::string Customer::get_customer_type() const {
    return customer_type;
}

// Account implementation

// Constructor for Account class
// Parameters:
// - account_type: The type of account (e.g., checking, savings)
Account::Account(const std::string& account_type) : balance(0.0), account_type(account_type) {}

// Deposits a specified amount into the account on a given date
// Parameters:
// - amount: The amount to deposit
// - date: The date of the transaction
void Account::deposit(double amount, const std::string& date) {
    balance += amount;
    transactions.push_back("DEP  " + date + "  $ " + std::to_string(amount) + "  $ " + std::to_string(balance));
}

// Withdraws a specified amount from the account on a given date
// Parameters:
// - amount: The amount to withdraw
// - date: The date of the transaction
void Account::withdraw(double amount, const std::string& date) {
    if (balance >= amount) {
        balance -= amount;
        transactions.push_back("WD   " + date + "  $ " + std::to_string(amount) + "  $ " + std::to_string(balance));
    } else {
        std::cout << "Insufficient balance!\n";
    }
}

// Getter for account balance
// Returns: The current balance of the account
double Account::get_balance() const {
    return balance;
}

// Getter for transaction history
// Returns: A vector of strings representing the transaction history
std::vector<std::string> Account::get_transactions() const {
    return transactions;
}

// Bank implementation

// Creates a new customer and adds them to the bank's customer list
// Parameters:
// - customer_type: The type of the customer (e.g., regular, premium)
// - name: The name of the customer
// - address: The address of the customer
// - phone: The phone number of the customer
void Bank::create_customer(const std::string& customer_type, const std::string& name, const std::string& address, const std::string& phone) {
    customers.push_back(std::make_unique<Customer>(name, address, phone, customer_type));
}

// Creates a new account and adds it to the bank's account list
// Parameters:
// - account_type: The type of account (e.g., checking, savings)
// Returns: A pointer to the newly created Account object
Account* Bank::create_account(const std::string& account_type) {
    accounts.push_back(std::make_unique<Account>(account_type));
    return accounts.back().get();
}

// Retrieves an account by its account number
// Parameters:
// - account_number: The index of the account in the accounts vector
// Returns: A pointer to the Account object, or nullptr if not found
Account* Bank::get_account(int account_number) {
    if (account_number >= 0 && account_number < accounts.size()) {
        return accounts[account_number].get();
    }
    return nullptr;
}

// Retrieves a customer by their account number
// Parameters:
// - account_number: The index of the customer in the customers vector
// Returns: A pointer to the Customer object, or nullptr if not found
Customer* Bank::get_customer(int account_number) {
    if (account_number >= 0 && account_number < customers.size()) {
        return customers[account_number].get();
    }
    return nullptr;
}

// Getter for the total number of accounts
// Returns: The count of accounts managed by the bank
int Bank::get_account_count() const {
    return accounts.size();
}
