#include "BankSystem.h"
#include <iostream>
#include <iomanip>
#include <string>

int main() {
    Bank bank;
    int option;

    while (true) {
        std::cout << "Select:\n";
        std::cout << "0: Add Account\n";
        std::cout << "1: Make Deposit\n";
        std::cout << "2: Make Withdrawal\n";
        std::cout << "3: Check Account\n";
        std::cout << "4: Exit\n";
        std::cout << "> ";
        std::cin >> option;

        if (option == 4) break; // Exit option

        switch (option) {
            case 0: { // Add Account
                std::cin.ignore();  // Clear newline from buffer
                std::string name, address, phone;
                int age, customer_type, account_type;

                std::cout << "Enter Customer Name> ";
                std::getline(std::cin, name);
                std::cout << "Enter Customer Address> ";
                std::getline(std::cin, address);
                std::cout << "Enter Customer Age> ";
                std::cin >> age;
                std::cout << "Enter Customer Phone Number> ";
                std::cin.ignore();
                std::getline(std::cin, phone);

                std::cout << "Select:\n";
                std::cout << "0: Senior\n";
                std::cout << "1: Adult\n";
                std::cout << "2: Student\n";
                std::cout << "> ";
                std::cin >> customer_type;

                bank.create_customer(customer_type == 0 ? "Senior" : customer_type == 1 ? "Adult" : "Student");

                std::cout << "Select:\n";
                std::cout << "0: Checking\n";
                std::cout << "1: Savings\n";
                std::cout << "> ";
                std::cin >> account_type;

                Account* account = bank.create_account(account_type == 0 ? "Checking" : "Savings");
                std::cout << "Account: " << (bank.get_account_count() - 1) << " Added\n";
                break;
            }

            case 1: { // Make Deposit
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
                std::cout << "Deposit in " << account_number << " amount: $" << std::fixed << std::setprecision(2) << amount << " on " << date << " new balance: $" << bank.get_account(account_number)->get_balance() << "\n";
                break;
            }

            case 2: { // Make Withdrawal
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
                std::cout << "Withdraw from " << account_number << " amount: $" << std::fixed << std::setprecision(2) << amount << " on " << date << " new balance: $" << bank.get_account(account_number)->get_balance() << "\n";
                break;
            }

            case 3: { // Check Account
                int account_number;
                std::cout << "Enter Account Number> ";
                std::cin >> account_number;

                Account* account = bank.get_account(account_number);
                std::cout << "Account: " << account_number << "\n";
                std::cout << "Owner: " << bank.get_customer(account_number)->get_name() << "\n";
                std::cout << "Type of customer: " << bank.get_customer(account_number)->get_customer_type() << "\n";
                std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account->get_balance() << "\n";

                // Print transaction history
                const std::vector<Transaction>& transactions = account->get_transactions();
                for (const auto& trans : transactions) {
                    std::cout << trans.to_string() << "\n";
                }
                break;
            }

            default:
                std::cout << "Invalid selection. Try again.\n";
                break;
        }
    }

    return 0;
}
