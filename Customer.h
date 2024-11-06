/* CheckingAccount.h
 * Module: Banking System - Checking Account Management
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This header file defines the `CheckingAccount` class, which extends from the `Account` class
 * and represents a checking account with specific methods for deposits, withdrawals, and interest calculations.
 */


#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

class Customer{

// Public variable accessible from the class instance
public:

    // Constructors
    /*
     * Construct a customer with the given value.
     * @param name as the customer name
     * @param address as the customer address
     * @param age as the customer age
     * @param telephone_number as the customer telephone number
     * @param customer_number as the customer number
     */

    // Constructor with parameters
    Customer(std::string name, std::string address,int age, std::string telephone_number,int customer_number);

    // Constructor without parameters
    Customer();


    // Accessor Functions
    /*
     * Gets the customer name
     * @return customer name
     */
    std::string get_name();
    /*
     * Gets the customer address
     * @return customer address
     */
    std::string get_address();
    /*
     * Gets the customer age
     * @return customer age
     */
    std::string get_age();
    /*
     * Gets the customer telephone number
     * @return customer telephone number
     */
    std::string get_telephone_number();
    /*
     * Gets the customer number
     * @return customer number
     */
    int get_customer_number();

    // Modifier Functions

    /*
     * Sets the customer name
     * @param name
     */
    void set_name(std::string name);
    /*
     * Sets the customer address
     * @param customer address
     */
    void set_address(std::string address);
    /*
     * Sets the customer address
     * @param customer address
     */
    void set_age(int age);
    /*
     * Sets the customer telephone number
     * @param customer telephone number
     */
    void set_telepgone_number(std::string telephone_number);
    /*
     * Sets the customer number
     * @param customer number
     */
    void set_customer_number(int customer_number);

private:
    // Data Fields
    /** String Data fields for the customer name */
    std::string name;
    /** String data field for the customer address */
    std::string address;
    /** Integer data field for the customer age */
    int age;
    /** String data field for the customer telephone number */
    std::string telephone_number;
    /** Integer data field for the customer number */
    int customer_number;

};

#endif /* CUSTOMER_H_ */
