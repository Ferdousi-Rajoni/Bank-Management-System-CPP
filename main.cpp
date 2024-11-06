/* main.cpp
* Module: Bank Account Management System
* Author: Jannatul Ferdousi Rajoni
* Date: 05/11/24
* Purpose: This program serves as the user interface for managing bank accounts.
*It allows users to create accounts, make deposits, withdrawals, and check account details.
*The program runs in a loop until the user decides to exit.
*
*/
  
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iomanip> 

#include "Date.h"
#include "time.h"
#include "Account.h"
#include "Customer.h"
#include "Bank.h"
#include "Senior.h"
#include "Student.h"
#include "Adult.h"
#include "Transaction.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

/*
 * Function Name: main
 * Purpose: Main executable file of basic banking system. Users can add multiple account.
 * 			Multiple transaction can be done. User can select customer as Senior, Adult and Student
 * 			and also select Savings account or checking account
 * Parameter(s): N/A
 * Precondition(s): N/A
 * Returns: N/A
 * Side Effect: N/A
 */

int main()
{
  /** Account no generation*/
  int account_no=0;
  /** This variable use as a input variable for the search account*/
  int search_account_no=0;
  /** This variable use for the customer transaction amount*/
  double transaction_amount=0;
  /** This variable used for customer no generation*/
  int customer_no=0;
  /** This variable for customer name input from the user*/
  string name;
  /** This variable use for customer address input from the user*/
  string address;
  /** This variable use for phone number input from the users*/
  string phone_number;
  /** This variable use for the customer age input from the user*/
  int age;
  /** This variable use for the date input from the user*/
  string date_concate;
  /** This variable use for delimate the day portion from the user inputed date*/
  int iday;
  /** This variable use for the delimate the month portion from the user inputed date*/
  int imonth;
  /** This variabke yse for the delimate the year portion from the user inputed date*/
  int iyear;
  /** This variable for take the information from the user about type of customer*/
  int type_customer;
  /** This variale store the information about customer account type*/
  int type_account;
  /** This variable store the application exit data*/
  int exit=0;
  /** This variable use for the user selection*/
  int user_selection;

  /** This the Bank class object.*/
  Bank bank;
  
  /** User operations started from here. If user select the option 4 then application will exit*/
  while (exit!=4)
  {
    cout << " Select: \n 0: Add Account \n 1: Make Deposit \n 2: Make Withdrawal \n 3: Check Account \n 4: Exit"<<endl;

    cin >> user_selection;
    switch (user_selection)
    {
      /** Add Account */
      case 0:
      {
        /** user input the customer name*/
        cout <<"Enter Customer Name: ";
        cin>>name;
        /** user input the customer address*/
        cout <<"Enter Customer Address: ";
        //getline(cin,address);
        //std::getline(std::cin, address); // Read the full line, including spaces
        cin>>address;
        /** user input the customer age*/
        cout<<"Enter Customer Age: ";
        cin>>age;
        /** user input the customer phone number*/
        cout<<"Enter Customer Phone Number: ";
        cin>>phone_number;

        /** User need to select the customer type for the account want to open*/
        cout << " Select: \n 0: Senior \n 1: Adult \n 2: Student"<<endl;
        cin>>type_customer;
        /** User need to select the account type for the account want to open*/
        cout<<"Select: \n 0: Checking \n 1: Savings"<<endl;
        cin>>type_account;
        /** Type customer 0 for the Senior*/
        if (type_customer==0)
        {
          customer_no=customer_no+1;
          Senior senior(name,address,age,phone_number,customer_no);
          /** Type account 0 for the checking account*/
          if (type_account==0)
          {
            CheckingAccount checking_account(senior,0,account_no,0,0);
            bank.add_account(checking_account);
            cout<<"Account: " <<account_no<<" added"<<endl;
            account_no=account_no+1;

          }
          /** Type account 1 for the saving account*/
          else if (type_account==1)
          {
            SavingsAccount savings_account(senior,0,account_no,0,1);
            bank.add_account(savings_account);
            cout<<"Account: " <<account_no<<" added"<<endl;
            account_no=account_no+1;
          }

        }
        /** Type customer 1 for the Adult*/
        else if (type_customer==1)
        {
          customer_no=customer_no+1;
          Adult adult(name,address,age,phone_number,customer_no);
          /** Type account 0 for the checking account*/
          if (type_account==0)
          {
            CheckingAccount checking_account(adult,0,account_no,1,0);
            bank.add_account(checking_account);
            cout<<"Account: " <<account_no<<" added"<<endl;
            account_no=account_no+1;

          }
          /** Type account 1 for the saving account*/
          else if (type_account==1)
          {
            SavingsAccount savings_account(adult,0,account_no,1,1);
            bank.add_account(savings_account);
            cout<<"Account: " <<account_no<<" added"<<endl;

            account_no=account_no+1;
          }
        }
        /** Type customer 1 for the Student*/
        else if (type_customer==2)
        {
          customer_no=customer_no+1;
          Student student(name,address,age,phone_number,customer_no);
          /** Type account 0 for the checking account*/
          if (type_account==0)
          {
            CheckingAccount checking_account(student,0,account_no,2,0);
            bank.add_account(checking_account);
            cout<<"Account: " <<account_no<<" added"<<endl;
            account_no=account_no+1;

          }
          /** Type account 1 for the saving account*/
          else if (type_account==1)
          {
            SavingsAccount savings_account(student,0,account_no,2,1);
            bank.add_account(savings_account);
            cout<<"Account: " <<account_no<<" added"<<endl;
            account_no=account_no+1;
          }

        }
        continue;
      }
      /** Make Deposit */
      case 1:
      {
        /** Enter the account number*/
        cout<<"Enter Account Number>" ;
        cin>>search_account_no;
        /** Enter the transaction amount*/
        cout<<"Enter The Amount>" ;
        cin>>transaction_amount;
        /** Enter the transaction date*/
        cout<<"Enter the date yyyy-mm-dd>" ;
        cin>>date_concate;

        /** From the date input we need to seperate day, month and year*/
        stringstream ss(date_concate);
        char delimiter; // To store the '-' characters

        // Extract year, month, and day
        ss >> iyear >> delimiter >> imonth >> delimiter >> iday;
        //cout<<iyear<<"  "<<imonth << "  "<< iday;
        /** Date creation from the date parameter*/
        Date date(iday,imonth,iyear);

        /** Calling the deposit function for depositing the amount*/
        bank.make_deposit(search_account_no,transaction_amount,date);

        /** Search the account from the accounts vector*/
        Account* acc=bank.get_account(search_account_no);

        /** Output after completing the sucessfull transaction*/
        cout<<"Deposit in " <<acc->get_account_number() <<" amount: $" <<transaction_amount<<" on "<< date<<" new balance: $"<<fixed<<setprecision(2) << acc->get_balance()<<endl;
        continue;
      }
      /** Make Withdrawal */
      case 2:
      {
        /** Enter the account number*/
        cout<<"Enter Account Number>" ;
        cin>>search_account_no;
        /** Enter the withdrawble balance*/
        cout<<"Enter The Amount>" ;
        cin>>transaction_amount;
        /** Enter the withdrawl date*/
        cout<<"Enter the date yyyy-mm-dd>" ;
        cin>>date_concate;

        /** From the date input we need to seperate day, month and year*/
        stringstream ss(date_concate);
        char delimiter; // To store the '-' characters

        // Extract year, month, and day
        ss >> iyear >> delimiter >> imonth >> delimiter >> iday;
        /** Date creation from the date parameter*/
        Date date(iday,imonth,iyear);
        /** This variable use for checking the successful withdrawal transaction*/
        bool wdyn=true;
        /** Calling the withdrawal function for depositing the amount*/
        wdyn=bank.make_withdrawl(search_account_no,transaction_amount,date);
        /** Search the account from the accounts vector*/
        Account* acc=bank.get_account(search_account_no);

        /** If transaction is sucessfull*/
        if (wdyn==true)
        {
          cout<<"Withdraw from " <<acc->get_account_number() <<" amount: $" <<transaction_amount<<" on "<< date<<" new balance: $"<<fixed<<setprecision(2) << acc->get_balance()<<endl;
        }
        /** If the transaction is failed*/
        else
        {
          cout<<"Insufficient Balance. Over draft penalty applied"<<endl;
        }
        continue;
      }
      ///** Check account
      case 3:
      {
        /** Enter the account number*/
        cout<<"Enter Account Number>" ;
        cin>>search_account_no;
        /** Search the account from the accounts vector*/
        Account* acc=bank.get_account(search_account_no);
        /** Prepare the output as per requirement*/
        cout<<"Account: "<<acc->get_account_number()<<endl;
        cout<<"Owner: "<<acc->get_customer().get_name()<<endl;
        string cust_type="";

        if (acc->type_customer()==0)
        {
          cust_type="Senior";
        }
        else if (acc->type_customer()==1)
        {
          cust_type="Adult";
        }
        else
        {
          cust_type="Student";
        }
        cout<<"Type of customer: "<<cust_type<<endl;
        cout<<"Balance: $"<<fixed<<setprecision(2)<<acc->get_balance()<<endl;
        cout<<acc->to_string();
        continue;
      }
      /** Exit from the application*/
      case 4:
      {
        cout << "You have Succesfully Exit from the Banking System" << endl;
        
        exit=4;
        break;
      }
      default:
      cout << "Invalid choice. Please select a valid option (1-4)." << endl;
    }
  }
  return 0;
}
