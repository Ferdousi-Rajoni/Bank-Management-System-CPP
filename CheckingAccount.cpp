/* CheckingAccount.cpp
 * Module: Banking System - Checking Account Management
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This file defines the `CheckingAccount` class, which extends from the `Account` class
 * and represents a checking account with specific methods for deposits, withdrawals, and interest calculations.
 */

#include "Customer.h"
#include "Account.h"
#include "CheckingAccount.h"
#include "Adult.h"
#include "Senior.h"
#include "Student.h"

/** Initialize the constructor
 * // Constructors
 * Construct a account with the given value.
 * @param Customer as the customer class
 * @param balance as the transaction balance
 * @param account_number as the customer account number
 * @param type_cust as the customer type
 * @param type_acc as the customer account type
 * */
CheckingAccount::CheckingAccount(Customer customer, double balance, int account_number, int type_cust,int type_acc): Account(customer, balance, account_number,type_cust,type_acc)
{

}

/*
 * Function Name: deposit
 * Purpose: This function deposited the amount into the customer account
 *
 * Parameter(s): @param amount is used for the transaction or deposited amount
 * Precondition(s): N/A
 * Returns: N/A
 * Side Effect: N/A
 */
void CheckingAccount::deposit(double amount){
    balance = balance + amount;
}

/*
 * Function Name: withdraw
 * Purpose: This function used for the withdrawal from the account
 *
 * Parameter(s): @param amount is used for the transaction or withdrawal amount
 * Precondition(s): N/A
 * Returns: @return true or false for the withdrawal is successful or not
 * Side Effect: N/A
 */
void CheckingAccount::withdraw(double amount){
    balance = balance - amount;
}

/*
 * Function Name: add_interest
 * Purpose: This function calculated the interest to the account
 *
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Returns: N/A
 * Side Effect: N/A
 */
void CheckingAccount::add_interest()
{
    double interest_rate=0;
    if (type_cust==0)
    {
        interest_rate=Senior::CHECK_INTEREST;
    }
    else if (type_cust==1)
    {
        interest_rate=Student::CHECK_INTEREST;
    }
    else if (type_cust==2)
    {
        interest_rate=Adult::CHECK_INTEREST;
    }
    balance=balance + (balance*interest_rate);
}
