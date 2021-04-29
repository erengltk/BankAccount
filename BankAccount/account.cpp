#include"account.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;
void account::create_account()
{
    accountnumber = rand();
    cout << "\nThe account Number is : " << accountnumber;
    cout << "\nEnter The Name of The account Holder : ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter account type (enter s - saving or c - credit): ";
    cin >> type;
    type = toupper(type);
    cout << "\nEnter The Initial amount(500 or more for Saving and 1000 or more for current ): ";
    cin >> deposit;
    cout << "\n\n\nAccount Created Successfully...";
}

void account::show_account()
{
    cout << "\nAccount Number: " << accountnumber;
    cout << "\nAccount Holder Name: " << name;
    cout << "\nType of Account: " << type;
    cout << "\nBalance amount: " << deposit;
}

void account::modify_account()
{
    cout << "\nAccount Number: " << accountnumber;
    cout << "\nModify Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account: ";
    cin >> type;
    type = toupper(type);
    // cout << "\nModify Balance amount: ";
    // cin >> deposit;
}

void account::deposit_funds(int x)
{
    deposit += x;
}

void account::draw_funds(int x)
{
    deposit -= x;
}

void account::get_report()
{
    cout << accountnumber << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int account::get_accountnumber()
{
    return accountnumber;
}

int account::get_funds()
{
    return deposit;
}

char account::get_accounttype()
{
    return type;
}