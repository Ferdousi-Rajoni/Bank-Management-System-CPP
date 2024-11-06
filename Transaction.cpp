/* Transaction.cpp
 * Module: Banking System - Transaction Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This file defines the `Transaction` class, which represents a financial transaction 
 * such as deposits, withdrawals, overdraft charges, cheque charges, and interest credits associated with customer accounts.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // Include sstream for ostringstream
#include <iomanip>  // Include iomanip for setw and right
#include "Transaction.h"

/*
 * Constructors
 * Construct a customer with the given value.
 * @param transaction type as the deposit/withdrwal/Overdraft charge/ Cheque Charge/ Interest Credit
 * @param amount as the withdraw/ deposit/cheque charge/ interest credit/overdraft amount
 * @param balance as customer balance
 * @param transaction date as the trasaction date
 */
Transaction::Transaction(std::string transaction_type, double amount, double balance, Date transaction_date)
{
    this->transaction_type=transaction_type;
    this->amount=amount;
    this->balance=balance;
    this->transaction_date=transaction_date;
}

/** This function returns the transaction details information*/
string Transaction::to_string()
{
    std::ostringstream oss;
    oss << std::right << std::setw(10) << transaction_type<< std::right << std::setw(15) << transaction_date<< std::right << std::setw(10) << "$ " <<std::right<< std::setw(10)<<fixed<<setprecision(2) << amount<< std::right << std::setw(10) << " $ " <<std::right<< std::setw(5) <<setprecision(2)<< balance<<endl;
    // Get the formatted string
    std::string output = oss.str();
    return output;
}

