/* Adult.cpp
 * Module: Bank Account Management System
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This implementation file defines the `Adult` class, which 
 * is a subclass of the `Customer` class. It represents an adult customer 
 * with attributes such as name, address, age, telephone number, and customer number. 
 * The `Adult` class provides a constructor that initializes these attributes 
 * by calling the parent `Customer` class constructor with the provided values.
 * The class serves as a representation of adult customers who may have specific 
 * banking account types and rules in the system.
 */

#include "Adult.h"

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
Adult::Adult(std::string name, std::string address, int age, std::string telephone_number, int customer_number)
    : Customer(name, address, age, telephone_number, customer_number) {}
