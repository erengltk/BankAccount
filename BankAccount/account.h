#pragma once
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;
class account
{
protected:
    int accountnumber;
    char name[50];
    int deposit;
    char type;

public:
    void create_account();
    void show_account();
    void modify_account();
    void deposit_funds(int);
    void draw_funds(int);
    void get_report();
    int get_accountnumber();
    int get_funds();
    char get_accounttype();
};