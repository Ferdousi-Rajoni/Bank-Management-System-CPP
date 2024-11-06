/* Senior.cpp
 * Module: Banking System - Senior Customer Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: This  file defines the `Senior` class, which inherits from the `Customer` class
 * and represents a senior customer with specific attributes and functionalities for senior customers.
 */

#include "Senior.h"

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
Senior::Senior(std::string name, std::string address, int age, std::string telephone_number, int customer_number)
    : Customer(name, address, age, telephone_number, customer_number) {}
