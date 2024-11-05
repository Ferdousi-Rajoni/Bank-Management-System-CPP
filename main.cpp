// main.cpp
// Module: Bank Account Management System
// Author: Jannatul Ferdousi Rajoni
// Date: 05/11/24
// Purpose: This program serves as the user interface for managing bank                  accounts.
//          It allows users to create accounts, make deposits, withdrawals,              and check account details.
//          The program runs in a loop until the user decides to exit.


#include <iostream>
#include <iomanip>
#include "BankSystem.h"



int main() {
    Bank bank; // Instantiate the Bank object
    int choice; // Variable to store user's menu choice

    while (true) {
        // Display the main menu
        std::cout << "Select:\n";
        std::cout << "0: Add Account\n";
        std::cout << "1: Make Deposit\n";
        std::cout << "2: Make Withdrawal\n";
        std::cout << "3: Check Account\n";
        std::cout << "4: Exit\n";
        std::cout << "> ";
        std::cin >> choice; // Get user's choice

        if (choice == 4) break; // Exit the loop if the user chooses to exit

        switch (choice) {
            case 0: { // Add Account
                std::cin.ignore(); // Ignore leftover newline from previous input
                std::string name, address, phone;
                int age, customer_option, account_option;

                // Gather customer details
                std::cout << "Enter Customer Name> ";
                std::getline(std::cin, name);
                std::cout << "Enter Customer Address> ";
                std::getline(std::cin, address);
                std::cout << "Enter Customer Age> ";
                std::cin >> age;
                std::cout << "Enter Customer Phone Number> ";
                std::cin >> phone;

                // Select customer type
                std::cout << "Select:\n0: Senior\n1: Adult\n2: Student\n> ";
                std::cin >> customer_option;
                std::string customer_type = (customer_option == 0) ? "Senior" : (customer_option == 1) ? "Adult" : "Student";

                // Call create_customer with gathered details
                bank.create_customer(customer_type, name, address, phone);

                // Select account type and create account without storing in a variable
                std::cout << "Select:\n0: Checking\n1: Savings\n> ";
                std::cin >> account_option;
                bank.create_account(account_option == 0 ? "Checking" : "Savings");

                // Display confirmation
                std::cout << "Account: " << (bank.get_account_count() - 1) << " Added\n";
                break;
            }

            case 1: { // Make Deposit
                int account_number; // Variable to store account number
                double amount; // Variable to store deposit amount
                std::string date; // Variable to store transaction date

                std::cout << "Enter Account Number> ";
                std::cin >> account_number;
                std::cout << "Enter The Amount> ";
                std::cin >> amount;
                std::cout << "Enter the date yyyy-mm-dd> ";
                std::cin >> date;

                // Get the account and perform the deposit
                Account* account = bank.get_account(account_number);
                if (account) {
                    account->deposit(amount, date);
                    std::cout << "Deposit in " << account_number << " amount: $"
                              << std::fixed << std::setprecision(2) << amount
                              << " on " << date << " new balance: $"
                              << account->get_balance() << "\n";
                } else {
                    std::cout << "Invalid Account Number\n";
                }
                break;
            }

            case 2: { // Make Withdrawal
                int account_number; // Variable to store account number
                double amount; // Variable to store withdrawal amount
                std::string date; // Variable to store transaction date

                std::cout << "Enter Account Number> ";
                std::cin >> account_number;
                std::cout << "Enter The Amount> ";
                std::cin >> amount;
                std::cout << "Enter the date yyyy-mm-dd> ";
                std::cin >> date;

                // Get the account and perform the withdrawal
                Account* account = bank.get_account(account_number);
                if (account) {
                    account->withdraw(amount, date);
                    std::cout << "Withdraw from " << account_number << " amount: $"
                              << std::fixed << std::setprecision(2) << amount
                              << " on " << date << " new balance: $"
                              << account->get_balance() << "\n";
                } else {
                    std::cout << "Invalid Account Number\n";
                }
                break;
            }

            case 3: { // Check Account
                int account_number; // Variable to store account number
                std::cout << "Enter Account Number> ";
                std::cin >> account_number;

                // Get account and customer details
                Account* account = bank.get_account(account_number);
                Customer* customer = bank.get_customer(account_number);
                if (account && customer) {
                    std::cout << "Account: " << account_number << "\n";
                    std::cout << "Owner: " << customer->get_name() << "\n";
                    std::cout << "Type of customer: " << customer->get_customer_type() << "\n";
                    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << account->get_balance() << "\n";

                    // Display transaction history
                    const std::vector<std::string>& transactions = account->get_transactions();
                    for (const auto& transaction : transactions) {
                        std::cout << "   " << transaction << "\n";
                    }
                } else {
                    std::cout << "Invalid Account Number\n";
                }
                break;
            }

            default: // Handle invalid option
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0; // End of the program
}
