#pragma once
#include"account.h"
class accountModifier : account
{
public:
	void create_account() override;
	void show_account() override;
	void modify_account() override;
	void deposit_funds(int) override;
	void draw_funds(int) override;
	void get_report() override;
	int get_accountnumber() override;
	int get_funds() override;
	char get_accounttype() override;
};