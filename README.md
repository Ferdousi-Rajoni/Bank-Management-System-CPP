*************************************************************
                      BANKING MANAGEMENT SYSTEM
*************************************************************

Author: Jannatul Ferdousi Rajoni
Student ID: 200530077
Date: 05/11/24

*************************************************************
DESCRIPTION:
*************************************************************
This C++ program simulates a simple banking system that allows users 
to create bank accounts, make deposits and withdrawals, and check 
account information. The program manages customer details and 
transactions, providing a simple console interface for interaction.

Users can create accounts with different types (Checking or Savings) 
and manage their transactions. The system records transactions, 
maintaining a history for each account.

*************************************************************
FILES INCLUDED:
*************************************************************
1. **main.cpp**:
   - Contains the main logic for the banking system, including user 
     interaction and calls to methods from the `Bank`, `Customer`, 
     and `Account` classes.

2. **Date.h**:
   - Header file defining the `Date` class, which manages and formats 
     transaction dates.

3. **Date.cpp**:
   - Implementation file for the `Date` class, providing methods 
     to handle and format date values.

4. **Bank.h**:
   - Header file defining the `Bank` class, which manages customer accounts 
     and transactions, allowing operations like creating accounts, handling deposits, 
     and withdrawals.

5. **Bank.cpp**:
   - Implementation file for the `Bank` class, where bank operations and 
     account management are carried out.

6. **Savings_Account.h**:
   - Header file defining the `SavingsAccount` class, a subclass of `Account` 
     with added functionality like interest calculation and specific customer rules.

7. **Savings_Account.cpp**:
   - Implementation of the `SavingsAccount` class methods, including 
     deposit, withdrawal, and adding interest based on customer type.

8. **Checking_Account.h**:
   - Header file defining the `CheckingAccount` class, a subclass of `Account` 
     with checking account-specific functionality like overdraft handling.

9. **Checking_Account.cpp**:
   - Implementation of the `CheckingAccount` class, managing operations 
     like overdrafts, deposits, and withdrawals.

10. **Account.h**:
    - Header file defining the base class `Account` with common methods 
      for deposit, withdrawal, and managing account balance.

11. **Account.cpp**:
    - Implementation of the `Account` class, including methods for 
      handling basic account operations like deposit and withdrawal.

12. **Transaction.h**:
    - Header file for the `Transaction` class, which handles different types 
      of transactions such as deposit, withdrawal, overdraft charges, and interest.

13. **Transaction.cpp**:
    - Implementation file for the `Transaction` class, which manages 
      transaction details and provides formatted transaction information.

14. **Customer.h**:
    - Header file for the `Customer` class, containing basic customer 
      details like name, address, age, telephone number, and account information.

15. **Customer.cpp**:
    - Implementation file for the `Customer` class, where the customer details 
      are initialized and managed.

16. **Senior.h**:
    - Header file defining the `Senior` subclass of `Customer`, with added 
      functionality and rules for senior customers.

17. **Senior.cpp**:
    - Implementation of the `Senior` class, which extends `Customer` 
      with senior-specific interest rates and rules.

18. **Adult.h**:
    - Header file defining the `Adult` subclass of `Customer`, containing 
      specific details for adult customers.

19. **Adult.cpp**:
    - Implementation of the `Adult` class, which inherits from `Customer` 
      and contains adult-specific functionality like interest rates.

20. **Student.h**:
    - Header file defining the `Student` subclass of `Customer`, with 
      student-specific rules for banking.

21. **Student.cpp**:
    - Implementation of the `Student` class, inheriting from `Customer` 
      with student-specific interest rates and other features.

*************************************************************
**How to Compile**
Use a C++ compiler to compile the program. Ensure that all files 
are in the same directory.

**How to Run**
Once compiled, run the program by executing the main function. 
Follow the on-screen instructions to:
1. Add a customer account by entering their details.
2. Perform deposits and withdrawals for the account.
3. Check account details and transaction history.

*************************************************************
FUNCTIONALITY:
*************************************************************
- **Account Creation**: 
  Users can create accounts by providing customer details and 
  selecting the type of account (e.g., Savings, Checking).

- **Deposits and Withdrawals**: 
  Users can deposit money into their accounts and withdraw funds, 
  with appropriate checks for sufficient balance.

- **Transaction History**: 
  The program keeps track of all transactions made within the 
  session, displaying this information when requested.

- **Interest Credit**: 
  For Savings accounts, interest is credited based on customer type 
  (Senior, Adult, Student).

- **Error Handling**: 
  The program ensures that only valid transactions (sufficient funds, 
  valid user input) are executed and prompts users for corrections.

*************************************************************
ERROR HANDLING:
*************************************************************
- The program checks for sufficient funds before allowing 
  withdrawals, providing feedback if funds are insufficient.

- Users are prompted to re-enter choices in case of invalid input.

- Invalid inputs (non-numeric values) during user interaction are 
  handled with error messages, ensuring the program continues smoothly.

*************************************************************
**References**
Additional information on Banking Management System is obtained from:
- Class notes and materials provided by Aymen Bin Said
- Stack Overflow (https://stackoverflow.com/)
- W3 Schools (https://www.w3schools.com/cpp/)

Email: ferdousi.rajoniii@gmail.com
GitHub: https://github.com/Ferdousi-Rajoni/Bank-Management-System-CPP
