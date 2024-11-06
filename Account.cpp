/* Account.cpp
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This file contains the implementation of the Account class. 
 * The Account class represents a bank account and provides functionality 
 * to store and manage account details, including the customer, balance, 
 * account type, and transaction history. It includes methods to access 
 * and modify account information, such as getting account details, 
 * setting balances, and recording transactions.
 * The class also provides a method for printing out the transaction 
 * history as a string
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // Include sstream for ostringstream
#include <iomanip>  // Include iomanip for setw and right
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

using namespace std;

/** Initialize the constructor
 * // Constructors
 * Construct a account with the given value.
 * @param Customer as the customer class
 * @param balance as the transaction balance
 * @param account_number as the customer account number
 * @param type_cust as the customer type
 * @param type_acc as the customer account type
 * */
Account::Account(Customer customer, double balance, int account_number,int type_cust,int type_acc )
{
    this->customer=customer;
    this->balance=balance;
    this->account_number=account_number;
    //create_account();
    //this->account_number=account_count;
    this->type_cust=type_cust;
    this->type_acc=type_acc;

}

/** Accessor Functions */
/*
 * Gets the account number
 * @return account number
 */
int Account::get_account_number() {
    return account_number;
}

/*
 * Gets the account balance
 * @return account balance
 */
double Account::get_balance(){
    return balance;
}

/*
 * Gets the customer
 * @return customer
 */
Customer Account::get_customer(){
    return customer;
}

/*
 * Gets the customer type
 * @return customer type
 * Return Customer type like Senior, Student etc. store: 0,1,2
 */

int Account::type_customer(){
    return type_cust;
}
/*
 * Gets the account type
 * @return account type
 * Return the account type like checking or saving accounts: 1,2
 */
int Account::type_account(){
    return type_acc;
}

/** Return the transactions output of vector */
vector<Transaction> Account::get_transaction(){
    return transactions;
}

/** Set the transactions into the transactions vector */
void Account::set_balance(string type_cust, double amount,double balance, Date cdate){
    this->balance=balance;
    Transaction newTransactions(type_cust,amount,balance,cdate);
    transactions.push_back(newTransactions);
}
/** This function print the transaction details*/
string Account::to_string()
{
    /** This is for storing the transaction*/
    string oss1;
    /** This is for storing the transaction and concate*/
    string oss;

    /** Read all transaction from the Transactions vector*/
    for(Transaction trans:transactions)
    {
        oss1=trans.to_string();
        oss=oss+oss1;

    }
    return oss;

}

