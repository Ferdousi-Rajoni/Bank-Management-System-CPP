/* Senior.h
 * Module: Banking System - Senior Customer Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `Senior` class, which inherits from the `Customer` class
 * and represents a senior customer with specific attributes and functionalities for senior customers.
 */

#ifndef SENIOR_H_
#define SENIOR_H_

#include <string>
#include <iostream>
#include "Customer.h"

class Senior: public Customer{

public:
    /** SAVINGS_INTEREST: Annual rate for senior savings interest */
    static constexpr  double SAVINGS_INTEREST= 0.04;
    /** CHECKING_INTEREST: Annual rate for senior checking interest */
    static constexpr  double CHECK_INTEREST = 0.01;
    /** CHECK_CHARGE: Per transaction fixed amount for senior check withdrawal charge */
    static constexpr  double CHECK_CHARGE =  0.01;
    /** OVERDRAFT_PENALTY: Fixed charge for the overdraft penalty, per transaction charge */
    static constexpr  double OVERDRAFT_PENALTY = 25.0;

    // Constructor
    // Constructors
    /*
     * Constructors
     * Construct a customer with the given value.
     * @param name as the customer name
     * @param address as the customer address
     * @param age as the customer age
     * @param telephone_number as the customer telephone number
     * @param customer_number as the customer number
     */
    Senior(std::string name, std::string address, int age, std::string telephone_number, int customer_number);

};

#endif /* SENIOR_H_ */
