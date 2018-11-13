#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Bank
{
  char name[20];
  char acctype;
  int accno;
  float balance;

public:
  Bank()
  {
    accno = 7;
    strcpy(name, "mainstream tushar");
    acctype = 's';
    balance = 0;
  }

  Bank(int accno, char name[20], char acctype)
  {
    this->accno = accno;
    strcpy(this->name, name);
    this->acctype = acctype;
    this->balance = 0;
  }

  Bank(Bank &object)
  {
    this->accno = object.accno;
    strcpy(this->name, object.name);
    this->acctype = object.acctype;
    this->balance = 0;
  }

  void initialise()
  {
      cin >> accno;
      cin.ignore();
      cin.getline(name, 20);
      cin >> acctype;
  }

  void deposit()
  {
    float amt;
    cin >> amt;

    balance += amt;
  }

  void withdraw()
  {
    float amt;
    cin >> amt;

    if(amt <= balance)
    {
      balance -= amt;
    }
    else
    {
      cout << "Insufficient balance." << endl;
    }
  }

  void display()
  {
    cout << accno << endl;
    cout << name << endl;
    cout << acctype << endl;
    cout << balance << endl;
  }
};


int main()
{
  Bank bank1;
  Bank bank2(150, "kanishk", 'S');
  Bank bank3(bank2);
  Bank bank4;
  bank4 = bank1;

  bank1.display();
  bank2.display();
  bank3.display();
  bank4.display();

  return 0;
}
