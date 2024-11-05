#include "BankSystem.h"
#include <iostream>
#include <iomanip>

int main() {
    Bank bank;
    int option;

    while (true) {
        std::cout << "Select:\n0: Add Account\n1: Make Deposit\n2: Make Withdrawal\n3: Check Account\n4: Exit\n> ";
        std::cin >> option;

      if (option == 0) {
          std::string name, address, phone, customer_type;
          int age, customer_option, account_option;

          std::cout << "Enter Customer Name> ";
          std::cin >> name;
          std::cout << "Enter Customer Address> ";
          std::cin >> address;
          std::cout << "Enter Customer Age> ";
          std::cin >> age;
          std::cout << "Enter Customer Phone Number> ";
          std::cin >> phone;
          std::cout << "Select:\n0: Senior\n1: Adult\n2: Student\n> ";
          std::cin >> customer_option;
          customer_type = (customer_option == 0) ? "Senior" : (customer_option == 1) ? "Adult" : "Student";
          bank.create_customer(customer_type);

          std::cout << "Select:\n0: Checking\n1: Savings\n> ";
          std::cin >> account_option;
          bank.create_account(account_option == 0 ? "Checking" : "Savings");
          std::cout << "Account: " << (bank.get_account_count() - 1) << " Added\n";
      }

        else if (option == 1) {
            int account_number;
            double amount;
            std::string date;

            std::cout << "Enter Account Number> ";
            std::cin >> account_number;
            std::cout << "Enter The Amount> ";
            std::cin >> amount;
            std::cout << "Enter the date yyyy-mm-dd> ";
            std::cin >> date;
            bank.get_account(account_number)->deposit(amount, date);
            std::cout << "Deposit in " << account_number << " amount: $" << std::fixed << std::setprecision(2) << amount
                      << " on " << date << " new balance: $" << bank.get_account(account_number)->get_balance() << "\n";
        } 
        else if (option == 2) {
            int account_number;
            double amount;
            std::string date;

            std::cout << "Enter Account Number> ";
            std::cin >> account_number;
            std::cout << "Enter The Amount> ";
            std::cin >> amount;
            std::cout << "Enter the date yyyy-mm-dd> ";
            std::cin >> date;
            bank.get_account(account_number)->withdraw(amount, date);
            std::cout << "Withdraw from " << account_number << " amount: $" << std::fixed << std::setprecision(2) << amount
                      << " on " << date << " new balance: $" << bank.get_account(account_number)->get_balance() << "\n";
        } 
        else if (option == 3) {
            int account_number;
            std::cout << "Enter Account Number> ";
            std::cin >> account_number;

            Account* account = bank.get_account(account_number);
            if (account) {
                Customer* customer = bank.get_customer(account_number);
                std::cout << "Account: " << account_number << "\n";
                std::cout << "Owner: " << customer->get_name() << "\n";
                std::cout << "Type of customer: " << customer->get_customer_type() << "\n";
                std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account->get_balance() << "\n";

                const std::vector<std::string>& transactions = account->get_transactions();
                for (const std::string& transaction : transactions) {
                    std::cout << "      " << transaction << "\n";
                }
            } else {
                std::cout << "Invalid account number.\n";
            }
        } 
        else if (option == 4) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }
    return 0;
}
