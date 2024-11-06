#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_


#include "Customer.h"
#include "Account.h"

class CheckingAccount: public Account {

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
    CheckingAccount(Customer customer, double balance, int account_number, int type_cust,int type_acc);

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

#endif /* CHECKINGACCOUNT_H_ */
