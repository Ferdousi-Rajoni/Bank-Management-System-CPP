/* Account.h
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file contains the declaration of the Account class, 
 * which represents a bank account. The Account class provides the structure 
 * for storing and managing account details, including customer information, 
 * account balance, account type, and transaction history. 
 * The class provides accessor and modifier functions for getting and setting 
 * account information, managing transactions, and converting account details 
 * to a string format. 
 * The header also includes a static member variable for keeping track of 
 * account numbers, ensuring each account has a unique identifier.
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "Customer.h"
#include "Transaction.h"

#include <vector>
using namespace std;

class Account{

    // Public variable accessible from the class instance
public:

    // Constructors
    /*
     * Constructors
     * Construct a account with the given value.
     * @param Customer as the customer class
     * @param balance as the transaction balance
     * @param account_number as the customer account number
     * @param type_cust as the customer type
     * @param type_acc as the customer account type
     */

    // Constructor with parameters
    //declare constructor with parameter
    Account( Customer customer, double balance, int account_number, int type_cust,int type_acc);
    //Account();

    // Accessor Functions
    /*
     * Accessor Functions
     * Gets the account number
     * @return account number
     */
    int get_account_number();
    /*
     * Accessor Functions
     * Gets the account balance
     * @return account balance
     */
    double get_balance();
    /*
     * Accessor Functions
     * Gets the customer type
     * @return customer type
     */
    int type_customer();
    /*
     * Accessor Functions
     * Gets the account type 1 for checking and 2 for saving account
     * @return account type
     */
    int type_account();

    /*
     * Accessor Functions
     * Gets the customer
     * @return customer
     */
    Customer get_customer();
    /*
     * Accessor Functions
     * Gets the transaction details
     * @return transaction details
     */
    vector<Transaction> get_transaction();

    // Modifier Functions
    /*
     * Modifier Functions
     * Gets the transaction details
     * @return transaction details
     */
    void set_customer(Customer customer);

    // Modifier Functions
    /**
     * Modifier Functions
     * This fuction set the customer information*/
    void set_balance(string type_cust, double amount,double balance, Date cdate);

    /**
     * Modifier Functions
     * This function returns the account details information*/
    string to_string();

    /** Create account number*/
    static int get_counter();

protected:
    /** This is class variable for the customer class*/
        Customer customer;
        /** This is store the account balance*/
        double balance;
        /** This is for the account number*/
        int account_number;
        /** This for the customer type information*/
        int type_cust;
        /** This is for the account type information*/
        int type_acc;
        /** This is for the transaction details store in array class*/
        vector<Transaction> transactions;
        /** This is for count the account no*/
        static int counter;
};

#endif /* ACCOUNT_H_ */
