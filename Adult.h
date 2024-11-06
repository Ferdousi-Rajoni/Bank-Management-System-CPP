/* Adult.h
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `Adult` class, which is a subclass of the 
 * `Customer` class. It represents adult customers in the bank account system. 
 * The class contains static constant variables for interest rates and charges 
 * applicable to adult customers. These include savings interest, checking 
 * interest, transaction charges for withdrawals, and overdraft penalties. 
 * The `Adult` class constructor initializes the customer's details such as name, 
 * address, age, telephone number, and customer number by calling the 
 * parent `Customer` class constructor.
 */


#ifndef ADULT_H_
#define ADULT_H_
#include "Customer.h"

class Adult: public Customer{

public:
    /** SAVINGS_INTEREST: Annual rate for student savings interest */
    static constexpr double SAVINGS_INTEREST = 0.03;
    /** CHECKING_INTEREST: Annual rate for student checking interest */
    static constexpr double CHECK_INTEREST = 0.1;
    /** CHECK_CHARGE: Per transaction fixed amount for student check withdrawal charge */
    static constexpr double CHECK_CHARGE = 0.3;
    /** OVERDRAFT_PENALTY: Fixed charge for the overdraft penalty, per transaction charge */
    static constexpr double OVERDRAFT_PENALTY = 25.0;

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
    Adult(std::string name, std::string address, int age, std::string telephone_number, int customer_number);

//public:
    /** SAVINGS_INTEREST: Annual rate for adult savings interest */
//	static const double SAVINGS_INTEREST;
    /** CHECKING_INTEREST: Annual rate for adult checking interest */
//	static const double CHECKING_INTEREST;
    /** CHECK_CHARGE: Per transaction fixed amount for adult check withdrawal charge */
//	static const double CHECK_CHARGE;
    /** OVERDRAFT_PENALTY: Fixed charge for the overdraft penalty, per transaction charge */
//	static const double OVERDRAFT_PENALTY;
};



#endif /* ADULT_H_ */
