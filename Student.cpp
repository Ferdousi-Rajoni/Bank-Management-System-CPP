/* Student.cpp
 * Module: Banking System - Student Customer Class
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose: Thisfile defines the `Student` class, which inherits from the `Customer` class
 * and represents a student customer with specific attributes and functionalities for student customers.
 */

#include "Student.h"

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

Student::Student(std::string name, std::string address, int age, std::string telephone_number, int customer_number)
    : Customer(name, address, age, telephone_number, customer_number) {}
