/* Bank.cpp
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This implementation file defines the `Bank` class, which is responsible for managing 
 * customer accounts. The class provides functions for adding accounts, making deposits, 
 * calculating and adding interest, processing withdrawals, and retrieving account details. 
 * The methods include logic to determine account types, calculate interest based on customer type, 
 * and apply overdraft penalties and transaction charges for withdrawals.
 */

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Bank.h"
#include "Adult.h"
#include "Senior.h"
#include "Student.h"
#include "Transaction.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Date.h"
using namespace std;

// Constructors
/*
 * Function Name: Bank
 * Purpose: Default constructor for the Bank class.
 * Parameter(s): None
 * Precondition(s): None
 * Returns: None
 * Side Effect: None
 */
Bank::Bank() {
    // TODO Auto-generated constructor stub
}

/*
 * Function Name: add_account
 * Purpose: Adds an account object to the bank's account collection (vector).
 * Parameter(s): @param account: The Account object to be added to the vector.
 * Precondition(s): None
 * Returns: None
 * Side Effect: The account is stored in the bank’s account collection.
 */
void Bank::add_account(Account account){
    accounts.push_back(account);
}

/*
 * Function Name: make_deposit
 * Purpose: Deposits a specified amount into a customer's account.
 * Parameter(s): @param account_number: The account number for the deposit.
 *              @param amount: The amount to deposit into the account.
 *              @param date: The date of the deposit transaction.
 * Precondition(s): The account with the specified account number must exist.
 * Returns: None
 * Side Effect: The balance of the account is updated after the deposit.
 */
void Bank::make_deposit(int account_number, double amount, Date date)
{
    Account* acc = get_account(account_number);
    double balance = 0;

    if (acc->type_account() == 0) { // Checking Account
        balance = acc->get_balance() + amount;
        acc->set_balance("DEP", amount, balance, date);
    }
    else if (acc->type_account() == 1) { // Savings Account
        balance = acc->get_balance() + amount;
        acc->set_balance("DEP", amount, balance, date);
    }
}

/*
 * Function Name: add_interest
 * Purpose: Calculates and adds interest to the account balance.
 * Parameter(s): @param account_number: The account number for the interest calculation.
 *              @param date: The date when the interest is added.
 * Precondition(s): The account with the specified account number must exist.
 * Returns: None
 * Side Effect: The balance of the account is updated after the interest is applied.
 */
void Bank::add_interest(int account_number, Date date)
{
    Account* acc = get_account(account_number);
    double balance = 0;
    double interest_rate = 0;
    double interest_amount = 0;

    if (acc->type_account() == 0) { // Checking Account
        if (acc->type_customer() == 0) { // Senior
            interest_rate = Senior::CHECK_INTEREST;
        }
        else if (acc->type_customer() == 1) { // Adult
            interest_rate = Adult::CHECK_INTEREST;
        }
        else if (acc->type_customer() == 2) { // Student
            interest_rate = Student::CHECK_INTEREST;
        }
    }
    else if (acc->type_account() == 1) { // Savings Account
        if (acc->type_customer() == 0) { // Senior
            interest_rate = Senior::SAVINGS_INTEREST;
        }
        else if (acc->type_customer() == 1) { // Adult
            interest_rate = Adult::SAVINGS_INTEREST;
        }
        else if (acc->type_customer() == 2) { // Student
            interest_rate = Student::SAVINGS_INTEREST;
        }
    }

    interest_amount = acc->get_balance() * interest_rate;
    balance = acc->get_balance() + interest_amount;
    acc->set_balance("INT CR", interest_amount, balance, date);
}

/*
 * Function Name: make_withdrawl
 * Purpose: Processes a withdrawal from the customer's account. If the balance is insufficient, 
 *          an overdraft penalty is applied.
 * Parameter(s): @param account_number: The account number for the withdrawal.
 *              @param amount: The amount to withdraw from the account.
 *              @param date: The date of the withdrawal transaction.
 * Precondition(s): The account with the specified account number must exist.
 * Returns: @return true if the withdrawal is successful, false if the balance is insufficient.
 * Side Effect: The balance of the account is updated after the withdrawal.
 */
bool Bank::make_withdrawl(int account_number, double amount, Date date)
{
    Account* acc = get_account(account_number);
    double charge_amount = 0;
    double balance = 0;
    double check_charge = 0;

    if (acc->type_customer() == 0) { // Senior
        charge_amount = Senior::OVERDRAFT_PENALTY;
        check_charge = Senior::CHECK_CHARGE;
    }
    else if (acc->type_customer() == 1) { // Adult
        charge_amount = Adult::OVERDRAFT_PENALTY;
        check_charge = Adult::CHECK_CHARGE;
    }
    else if (acc->type_customer() == 2) { // Student
        charge_amount = Student::OVERDRAFT_PENALTY;
        check_charge = Student::CHECK_CHARGE;
    }

    if (acc->type_account() == 0) { // Checking Account
        if (acc->get_balance() >= amount) {
            balance = acc->get_balance() - amount;
            acc->set_balance("WD", amount, balance, date);
            balance = balance - check_charge;
            acc->set_balance("CHKCHG", check_charge, balance, date);
            return true;
        }
        else {
            balance = acc->get_balance() - charge_amount;
            acc->set_balance("ODF", charge_amount, balance, date);
            return false;
        }
    }
    else { // Savings Account
        if (acc->get_balance() >= amount) {
            balance = acc->get_balance() - amount;
            acc->set_balance("WD", amount, balance, date);
            balance = balance - check_charge;
            acc->set_balance("CHKCHG", check_charge, balance, date);
            return true;
        }
        else {
            balance = acc->get_balance() - charge_amount;
            acc->set_balance("ODF", charge_amount, balance, date);
            return false;
        }
    }
}

/*
 * Function Name: get_account
 * Purpose: Retrieves an account object from the bank's account collection based on the 
 *          specified account number.
 * Parameter(s): @param account_number: The account number to identify the account.
 * Precondition(s): The account with the specified account number must exist.
 * Returns: @return Account object corresponding to the specified account number, or nullptr if not found.
 * Side Effect: None
 */
Account* Bank::get_account(int account_number)
{
    for (Account& account : accounts) {
        if (account.get_account_number() == account_number) {
            return &account;
        }
    }
    return nullptr;
}
