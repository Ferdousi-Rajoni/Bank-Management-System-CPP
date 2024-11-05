// BankSystem.h
// Module: Bank Account Management System
// Author: Jannatul Ferdousi Rajoni
// Date: 05/11/24
// Purpose: Declaration of the Customer, Account, and Bank classes. 
// The Bank System manages customers and their accounts, 
// allowing for deposits, withdrawals, and transaction tracking for each account.


#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <string>
#include <vector>
#include <memory>

/**
 * @class Customer
 * @brief Represents a bank customer.
 * 
 * This class encapsulates customer information such as name, address,
 * phone number, and type of customer.
 */
class Customer {
public:
    /**
     * @brief Constructs a Customer object with provided details.
     * 
     * @param name The name of the customer.
     * @param address The address of the customer.
     * @param phone The phone number of the customer.
     * @param customer_type The type of customer (e.g., Adult, Senior, Student).
     */
    Customer(const std::string& name, const std::string& address, const std::string& phone, const std::string& customer_type);

    /**
     * @brief Retrieves the name of the customer.
     * 
     * @return A string representing the customer's name.
     */
    std::string get_name() const;

    /**
     * @brief Retrieves the type of customer.
     * 
     * @return A string representing the customer's type.
     */
    std::string get_customer_type() const;

private:
    std::string name; // The name of the customer.
    std::string address; //The address of the customer.
    std::string phone; //The phone number of the customer.
    std::string customer_type; //The type of the customer.
};

/**
 * @class Account
 * @brief Represents a bank account.
 * 
 * This class manages account balance, allows deposits and withdrawals,
 * and tracks transactions related to the account.
 */
class Account {
public:
    /**
     * @brief Constructs an Account object of a specified type.
     * 
     * @param account_type The type of account (e.g., Checking, Savings).
     */
    Account(const std::string& account_type);

    /**
     * @brief Deposits a specified amount into the account.
     * 
     * @param amount The amount to be deposited.
     * @param date The date of the deposit.
     */
    void deposit(double amount, const std::string& date);

    /**
     * @brief Withdraws a specified amount from the account.
     * 
     * @param amount The amount to be withdrawn.
     * @param date The date of the withdrawal.
     */
    void withdraw(double amount, const std::string& date);

    /**
     * @brief Retrieves the current balance of the account.
     * 
     * @return The current balance as a double.
     */
    double get_balance() const;

    /**
     * @brief Retrieves the list of transactions performed on the account.
     * 
     * @return A vector of strings representing the transactions.
     */
    std::vector<std::string> get_transactions() const;

private:
    double balance; // The current balance of the account.
    std::string account_type; //The type of account.
    std::vector<std::string> transactions; // A list of transactions for the account.
};

/**
 * @class Bank
 * @brief Manages the customers and accounts within the bank.
 * 
 * This class provides functionalities to create customers and accounts,
 * retrieve them, and track the number of accounts in the bank.
 */
class Bank {
public:
    /**
     * @brief Creates a new customer and adds it to the bank.
     * 
     * @param customer_type The type of customer (e.g., Adult, Senior, Student).
     * @param name The name of the customer.
     * @param address The address of the customer.
     * @param phone The phone number of the customer.
     */
    void create_customer(const std::string& customer_type, const std::string& name, const std::string& address, const std::string& phone);

    /**
     * @brief Creates a new account and adds it to the bank.
     * 
     * @param account_type The type of account (e.g., Checking, Savings).
     * @return A pointer to the created Account object.
     */
    Account* create_account(const std::string& account_type);

    /**
     * @brief Retrieves an account by its number.
     * 
     * @param account_number The number of the account to retrieve.
     * @return A pointer to the Account object, or nullptr if not found.
     */
    Account* get_account(int account_number);

    /**
     * @brief Retrieves a customer by the account number.
     * 
     * @param account_number The number of the account for which to find the customer.
     * @return A pointer to the Customer object, or nullptr if not found.
     */
    Customer* get_customer(int account_number);

    /**
     * @brief Retrieves the total number of accounts in the bank.
     * 
     * @return The total number of accounts as an integer.
     */
    int get_account_count() const;

private:
    std::vector<std::unique_ptr<Customer>> customers; ///< A vector of unique pointers to customers.
    std::vector<std::unique_ptr<Account>> accounts; ///< A vector of unique pointers to accounts.
};

#endif // BANK_SYSTEM_H
