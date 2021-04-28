#include"account-executer.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
using namespace std;
class accountExecuter : accountModifier
{
public:
	void write_account()
	{
		accountModifier ac;
		ofstream outFile;
		outFile.open("account.dat", ios::binary | ios::app);
		ac.create_account();
		outFile.write(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
		outFile.close();
	}
	void display_sp(int n)
	{
        accountModifier ac;
        bool flag = false;
        ifstream inFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        cout << "\nBALANCE DETAILS\n";

        while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(accountModifier)))
        {
            if (ac.get_accountnumber() == n)
            {
                ac.show_account();
                flag = true;
            }
        }
        inFile.close();
        if (flag == false)
            cout << "\n\nAccount number does not exist";
	}
    void modify_account(int n)
    {
        bool found = false;
        accountModifier ac;
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        while (!File.eof() && found == false)
        {
            File.read(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
            if (ac.get_accountnumber() == n)
            {
                ac.show_account();
                cout << "\n\nEnter The New Details of account: " << endl;
                ac.modify_account();
                int pos = (-1) * static_cast<int>(sizeof(accountModifier));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
                cout << "\n\n\t Record Updated...";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
    }
    void delete_account(int n)
    {
        accountModifier ac;
        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        outFile.open("Temp.dat", ios::binary);
        inFile.seekg(0, ios::beg);
        while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(accountModifier)))
        {
            if (ac.get_accountnumber() != n)
            {
                outFile.write(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
            }
        }

        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat", "account.dat");
        cout << "\n\n\tRecord Deleted...";
    }
    void display_all()
    {
        int bankPassword = 111, enteredPassword;
        cout << "Enter the BANK PASSWORD: \n";
        cin >> enteredPassword;
        if (enteredPassword == bankPassword)
        {
            accountModifier ac;
            ifstream inFile;
            inFile.open("account.dat", ios::binary);
            if (!inFile)
            {
                cout << "File could not be open !! Press any Key...";
                return;
            }

            cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
            cout << "====================================================\n";
            cout << "Account No.      Name           Type      Balance\n";
            cout << "====================================================\n";
            while (inFile.read(reinterpret_cast<char*>(&ac), sizeof(accountModifier)))
            {
                ac.get_report();
            }
            inFile.close();

        }
        else {
            cout << "Please enter the correct password.\n";
        }
    }
    void deposit_withdraw(int n, int option)
    {
        int amt;
        bool found = false;
        accountModifier ac;
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }
        while (!File.eof() && found == false)
        {
            File.read(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
            if (ac.get_accountnumber() == n)
            {
                ac.show_account();
                if (option == 1)
                {
                    cout << "\n\n\tTO DEPOSITE AMOUNT ";
                    cout << "\n\nEnter The amount to be deposited: ";
                    cin >> amt;
                    ac.deposit_funds(amt);
                }
                if (option == 2)
                {
                    cout << "\n\n\tTO WITHDRAW AMOUNT ";
                    cout << "\n\nEnter The amount to be withdraw: ";
                    cin >> amt;
                    int bal = ac.get_funds() - amt;
                    if ((bal < 500 && ac.get_accounttype() == 'S') || (bal < 1000 && ac.get_accounttype() == 'C'))
                        cout << "Insufficience balance";
                    else
                        ac.draw_funds(amt);
                }
                int pos = (-1) * static_cast<int>(sizeof(ac));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char*>(&ac), sizeof(accountModifier));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
    }
};
