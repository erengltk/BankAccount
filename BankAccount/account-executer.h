#pragma once
#include"account-modifier.h"
class accountExecuter : accountModifier
{
public:
	void write_account();
	void display_sp(int);
	void modify_account(int);
	void delete_account(int);
	void display_all();
	void deposit_withdraw(int, int);
};
