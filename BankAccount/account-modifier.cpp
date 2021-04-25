#include"account-modifier.h"
#include<iostream>
#include <iomanip>
using namespace std;
class accountModifier : account
{
public:
	void create_account() override
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
	void show_account() override
	{
		cout << "\nAccount Number: " << accountnumber;
		cout << "\nAccount Holder Name: " << name;
		cout << "\nType of Account: " << type;
		cout << "\nBalance amount: " << deposit;
	}
	void modify_account() override
	{
		cout << "\nAccount Number: " << accountnumber;
		cout << "\nModify Account Holder Name: ";
		cin.ignore();
		cin.getline(name, 50);
		cout << "\nModify Type of Account: ";
		cin >> type;
		type = toupper(type);
	}
	void deposit_funds(int x) override
	{
		deposit += x;
	}
	void draw_funds(int x) override
	{
		deposit -= x;
	}
	void get_report() override
	{
		cout << accountnumber << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
	}
	int get_accountnumber() override
	{
		return accountnumber;
	}
	int get_funds() override
	{
		return deposit;
	}
	char get_accounttype() override
	{
		return type;
	}
};
