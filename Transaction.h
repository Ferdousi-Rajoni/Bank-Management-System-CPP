/* Transaction.h
 * Module: Banking System - Transaction Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `Transaction` class, which represents a financial transaction 
 * such as deposits, withdrawals, overdraft charges, cheque charges, and interest credits associated with customer accounts.
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <iostream>
#include <string>
#include <time.h>
#include "Date.h"

using namespace std;

class Transaction{

// Public variable accessible from the class instance
public:

    // Constructors
    /*
     * Constructors
     * Construct a customer with the given value.
     * @param transaction type as the deposit/withdrwal/Overdraft charge/ Cheque Charge/ Interest Credit
     * @param amount as the withdraw/ deposit/cheque charge/ interest credit/overdraft amount
     * @param balance as customer balance
     * @param transaction date as the trasaction date
     */

    // Constructor with parameters
    Transaction(std::string transaction_type, double amount, double balance, Date transaction_date);

    // Constructor without parameters
    Transaction();

    /** This function returns the transaction details information*/
    string to_string();

private:

    /** transaction_type: store the transaction type deposit/ withdrawal/ Interest CR/ Check Charge/ Overdraft Penalty */
    string transaction_type;
    /** amount: store the transaction amount */
    double amount;
    /** balance: store the after transaction balance */
    double balance;
    /** transaction_time: store the transaction time */
    Date transaction_date;
};


#endif /* TRANSACTION_H_ */
