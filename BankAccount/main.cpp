#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include"account.h"
#include"account-modifier.h"
#include"account-executer.h"
using namespace std;

int main()
{
    accountExecuter aE;
    srand(time(0));
    char opt;
    int num;
    for (;;)
    {
        system("color 05");
        system("cls");

        cout << "\n\t\tPress 1 to Create New Account";
        cout << "\n\t\tPress 2 to Deposit Funds";
        cout << "\n\t\tPress 3 to Withdraw Funds";
        cout << "\n\t\tPress 4 to Check Balance";
        cout << "\n\t\tPress 5 to View All Account Holder";
        cout << "\n\t\tPress 6 to Close an Account";
        cout << "\n\t\tPress 7 to Modify an Account";
        cout << "\n\t\tPress 8 to Exit the Program";
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\n\t\tOption: ";
        cin >> opt;
        system("cls");
        switch (opt)
        {
        case '1':
            system("color 02");
            aE.write_account();
            break;
        case '2':
            system("color 03");
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            aE.deposit_withdraw(num, 1);
            break;
        case '3':
            system("color 06");
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            aE.deposit_withdraw(num, 2);
            break;
        case '4':
            system("color 08");
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            aE.display_sp(num);
            break;
        case '5':
            system("color 9");
            aE.display_all();
            break;
        case '6':
            system("color 10");
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            aE.delete_account(num);
            break;
        case '7':
            system("color 11");
            cout << "\n\n\tEnter The account No. : ";
            cin >> num;
            aE.modify_account(num);
            break;
        case '8':
            system("color 04");
            cout << "\n\n\tThanks for using Bank Management System";
            break;
        default:
            cout << "Invalid Option\n";
        }
        cin.ignore();
        cin.get();
        if (opt == '8')
            break;
    }
    return 0;
}