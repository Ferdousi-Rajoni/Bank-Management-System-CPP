/* Student.h
 * Module: Banking System - Student Customer Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `Student` class, which inherits from the `Customer` class
 * and represents a student customer with specific attributes and functionalities for student customers.
 */


#ifndef STUDENT_H_
#define STUDENT_H_


#include <string>
#include <iostream>
#include "Customer.h"

class Student: public Customer{
public:
    /** SAVINGS_INTEREST: Annual rate for student savings interest */
    static constexpr double SAVINGS_INTEREST = 0.04;
    /** CHECKING_INTEREST: Annual rate for student checking interest */
    static constexpr double CHECK_INTEREST = 0.1;
    /** CHECK_CHARGE: Per transaction fixed amount for student check withdrawal charge */
    static constexpr double CHECK_CHARGE = 0.2;
    /** OVERDRAFT_PENALTY: Fixed charge for the overdraft penalty, per transaction charge */
    static constexpr double OVERDRAFT_PENALTY = 25.0;

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
    Student(std::string name, std::string address, int age, std::string telephone_number, int customer_number);
};


#endif /* STUDENT_H_ */

