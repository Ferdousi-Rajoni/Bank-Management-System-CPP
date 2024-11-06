/* SavingsAccount.cpp
 * Module: Banking System - Savings Account Management
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `SavingsAccount` class, which extends from the `Account` class
 * and represents a savings account with specific methods for deposits, withdrawals, and interest calculations.
 */

#include "Customer.h"
#include "Account.h"
#include "SavingsAccount.h"
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
SavingsAccount::SavingsAccount(Customer customer, double balance, int account_number, int type_cust,int type_acc): Account(customer, balance, account_number,type_cust,type_acc)
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
void SavingsAccount::deposit(double amount){
    balance = balance + amount;
}

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
void SavingsAccount::withdraw(double amount){
    balance = balance - amount;
}

// set interest into the savings balance
/*
     * Function Name: add_interest
     * Purpose: This function calculated the interest to the account
     *
     * Parameter(s): N/A
     * Precondition(s): N/A
     * Returns: N/A
     * Side Effect: N/A
     */
void SavingsAccount::add_interest()
{
    double interest_rate=0;
    if (type_cust==0) //Senior
    {
        interest_rate=Senior::SAVINGS_INTEREST;
    }
    else if (type_cust==1) //Adult
    {
        interest_rate=Adult::SAVINGS_INTEREST;
    }
    else if (type_cust==2) //Student
    {
        interest_rate=Student::SAVINGS_INTEREST;
    }
    balance=balance + (balance*interest_rate);

}







