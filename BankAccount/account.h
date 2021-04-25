#pragma once
class account
{
protected:
    int accountnumber;
    char name[50];
    int deposit;
    char type;

public:
   virtual void create_account()=0;
   virtual void show_account()=0;
   virtual void modify_account()=0;
   virtual void deposit_funds(int)=0;
   virtual void draw_funds(int)=0;
   virtual void get_report()=0;
   virtual int get_accountnumber()=0;
   virtual int get_funds()=0;
   virtual char get_accounttype()=0;
};