#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include <string>
#include <vector>
#include <memory>

// Forward declaration
class Account;

class Customer {
public:
    Customer(const std::string& name, const std::string& address, int age, const std::string& phone, const std::string& customer_type);
    std::string get_name() const;
    std::string get_customer_type() const;

private:
    std::string name;
    std::string address;
    int age;
    std::string phone;
    std::string customer_type;
};

class Account {
public:
    Account(const std::string& account_type);
    void deposit(double amount, const std::string& date);
    void withdraw(double amount, const std::string& date);
    double get_balance() const;
    std::vector<std::string> get_transactions() const;

private:
    double balance;
    std::string account_type;
    std::vector<std::string> transactions;
};

class Bank {
public:
    void create_customer(const std::string& customer_type);
    Account* create_account(const std::string& account_type);
    Account* get_account(int account_number);
    Customer* get_customer(int account_number);
    int get_account_count() const;

private:
    std::vector<std::unique_ptr<Customer>> customers;
    std::vector<std::unique_ptr<Account>> accounts;
};

#endif // BANK_SYSTEM_H
