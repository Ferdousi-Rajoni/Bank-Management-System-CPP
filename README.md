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

2. **BankSystem.h**:
   - The header file defining the `Customer`, `Account`, and `Bank` 
     classes, including their methods and attributes.

3. **BankSystem.cpp**:
   - The implementation file for the `Customer`, `Account`, and 
     `Bank` classes. It implements the methods declared in the 
     header file (`BankSystem.h`).

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
  selecting the type of account.

- **Deposits and Withdrawals**: 
  Users can deposit money into their accounts and withdraw funds, 
  with appropriate checks for sufficient balance.

- **Transaction History**: 
  The program keeps track of all transactions made within the 
  session, displaying this information when requested.

*************************************************************
ERROR HANDLING:
*************************************************************
- The program checks for sufficient funds before allowing 
  withdrawals, providing feedback if funds are insufficient.

- Users are prompted to re-enter choices in case of invalid input.

*************************************************************
**References**
Additional information on BankingManagementSystem is obtained from
- Class notes and materials provide by Aymen Bin Said
- Stackoverflow (https://stackoverflow.com/)
- W3 schools(https://www.w3schools.com/cpp/)

Email: ferdousi.rajoniii@gmail.com
GitHub:https://github.com/Ferdousi-Rajoni/Bank-Management-System-CPP
