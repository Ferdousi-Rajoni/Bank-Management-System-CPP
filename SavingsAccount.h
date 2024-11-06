/* SavingsAccount.h
 * Module: Banking System - Savings Account Management
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `SavingsAccount` class, which extends from the `Account` class
 * and represents a savings account with specific methods for deposits, withdrawals, and interest calculations.
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount:public Account{

public:
    /** Initialize the constructor
     * // Constructors
     * Construct a account with the given value.
     * @param Customer as the customer class
     * @param balance as the transaction balance
     * @param account_number as the customer account number
     * @param type_cust as the customer type
     * @param type_acc as the customer account type
     * */
    SavingsAccount(Customer customer, double balance, int account_number, int type_cust, int type_acc);
    /*
     * Function Name: deposit
     * Purpose: This function deposited the amount into the customer account
     *
     * Parameter(s): @param amount is used for the transaction or deposited amount
     * Precondition(s): N/A
     * Returns: N/A
     * Side Effect: N/A
     */
    void deposit(double amount);
    //With drawn the amount from saving account
    /*
     * Function Name: withdraw
     * Purpose: This function used for the withdrawal from the account
     *
     * Parameter(s): @param amount is used for the transaction or withdrawal amount
     * Precondition(s): N/A
     * Returns: @return true or false for the withdrawal is successful or not
     * Side Effect: N/A
     */
    void withdraw(double amount);
    /*
     * Function Name: add_interest
     * Purpose: This function calculated the interest to the account
     *
     * Parameter(s): N/A
     * Precondition(s): N/A
     * Returns: N/A
     * Side Effect: N/A
     */
    void add_interest();

};

#endif /* SAVINGSACCOUNT_H_ */
