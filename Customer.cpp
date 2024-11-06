/* CheckingAccount.cpp
 * Module: Banking System - Checking Account Management
 * Author: Jannatul Ferdousi Rajoni
 * Date: 05/11/24
 * Purpose:This is a implementation file for Customer.
 *  		Data Fields: Name, address, telephone_number, customer_number
 *  			 And having the below member functions:
 *  			 Constructor
 *  			 Default Constructor
 *  			 Get & Set Customer Name
 *  			 Get & Set Customer Address
 *  			 Get & Set Customer Age
 *  			 Get & Set Telephone Number
 *  			 Get & Set Customer Number
 */


#include <string>
#include <iostream>
#include "Customer.h"

// Constructors
/*
 * Construct a customer with the given value.
 * @param name as the customer name
 * @param address as the customer as address
 * @param telephone_number as the customer telephone number
 * @param customer_number as the customer number
 */

// Constructor with parameters
Customer::Customer(std::string name, std::string address,int age, std::string telephone_number,int customer_number)
{
    this->name=name;
    this->address=address;
    this->age=age;
    this->telephone_number=telephone_number;
    this->customer_number=customer_number;
}

// Constructor without parameters
Customer::Customer()
{
    this->name="";
    this->address="";
    this->age=0;
    this->telephone_number="";
    this->customer_number=0;
}


// Accessor Functions
/*
 * Accessor Functions
 * Gets the customer name
 * @return customer name
 */
std::string Customer::get_name()
{
    return name;
}
/*
 * Accessor Functions
 * Gets the customer address
 * @return customer address
 */
std::string Customer::get_address()
{
    return address;
}
/*
 * Accessor Functions
 * Gets the customer telephone number
 * @return customer telephone number
 */
std::string Customer::get_telephone_number()
{
    return telephone_number;
}
/*
 * Accessor Functions
 * Gets the customer number
 * @return customer number
 */
int Customer::get_customer_number()
{
    return customer_number;
}


// Modifier Functions

/*
 * Modifier Functions
 * Sets the customer name
 * @param name
 */
void Customer::set_name(std::string name)
{
    this->name=name;
}
/*
 * Modifier Functions
 * Sets the customer address
 * @param customer address
 */
void Customer::set_address(std::string address)
{
    this->address=address;
}
/*
 * Modifier Functions
 * Sets the customer telephone number
 * @param customer telephone number
 */
void Customer::set_telepgone_number(std::string telephone_number)
{
    this->telephone_number=telephone_number;
}
/*
 * Modifier Functions
 * Sets the customer number
 * @param customer number
 */
void Customer::set_customer_number(int customer_number)
{
    this->customer_number=customer_number;
}




