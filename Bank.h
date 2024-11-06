/* Bank.h
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the interface of the `Bank` class. The `Bank` class manages 
 * customer accounts and provides methods for adding accounts, making deposits, processing 
 * withdrawals, adding interest, and retrieving account information.
 */

#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Date.h"

using namespace std;

// Bank Class Definition
class Bank {

public:
    // Constructors
    /*
     * Function Name: Bank
     * Purpose: Default constructor for the Bank class.
     * Precondition(s): None
     * Returns: None
     * Side Effect: None
     */
    Bank();

    // Member Functions
    /*
     * Function Name: add_account
     * Purpose: Adds an account to the bank's collection of accounts.
     * Parameter(s): @param account: The Account object to add.
     * Precondition(s): None
     * Returns: None
     * Side Effect: Adds the account to the accounts vector.
     */
    void add_account(Account account);

    /*
     * Function Name: make_deposit
     * Purpose: Deposits a specified amount into a customer’s account.
     * Parameter(s): @param account_number: The account number for the deposit.
     *              @param amount: The deposit amount.
     *              @param date: The date of the deposit transaction.
     * Precondition(s): The account number must exist in the bank’s accounts.
     * Returns: None
     * Side Effect: Updates the balance of the account after deposit.
     */
    void make_deposit(int account_number, double amount, Date date);

    /*
     * Function Name: make_withdrawl
     * Purpose: Withdraws a specified amount from a customer’s account.
     * Parameter(s): @param account_number: The account number for the withdrawal.
     *              @param amount: The withdrawal amount.
     *              @param date: The date of the withdrawal transaction.
     * Precondition(s): The account number must exist in the bank’s accounts.
     * Returns: @return true if the withdrawal is successful, false otherwise.
     * Side Effect: Updates the balance of the account after withdrawal.
     */
    bool make_withdrawl(int account_number, double amount, Date date);

    /*
     * Function Name: add_interest
     * Purpose: Adds interest to the account balance based on account type and customer type.
     * Parameter(s): @param account_number: The account number for the interest calculation.
     *              @param date: The date when the interest is added.
     * Precondition(s): The account number must exist in the bank’s accounts.
     * Returns: None
     * Side Effect: Updates the balance of the account after adding interest.
     */
    void add_interest(int account_number, Date date);

    /*
     * Function Name: get_account
     * Purpose: Retrieves the account information for a specified account number.
     * Parameter(s): @param account_number: The account number to search for.
     * Precondition(s): The account number must exist in the bank’s accounts.
     * Returns: @return A pointer to the Account object, or nullptr if the account does not exist.
     * Side Effect: None
     */
    Account* get_account(int account_number);

private:
    vector<Account> accounts; // Collection of all accounts managed by the bank.
};

#endif /* BANK_H_ */
