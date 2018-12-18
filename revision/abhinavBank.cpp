#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class bank
{
  long balance;
  int acc_no;
  char name[20];
  char type[10];

public:
  bank();
  void get();
  void deposit(int );
  void withdraw(int );
  void display();
}b;
bank::bank()
{
  strcpy(name,"notdefined");
  strcpy(type,"no");
  acc_no=0;
  balance=1000;
}
void bank::get()
{
  cin.ignore();
  cout<<"\nenter the name of the account holder : ";
  gets(name);
  cin.ignore();
  cout<<"\nenter the account type : ";
  cin.getline(type,10);
    cout<<"enter bank account number : ";
    cin>>acc_no;



}
void bank::deposit(int money)
{
      balance=balance+money;
}
void bank::withdraw(int money)
{
  int flag;
  flag=balance-money;
  if(flag>1000)
  {balance=flag;
  cout<<"\nmoney added is : "<<money;}
  else
  cout<<"balance not enough\n";
}
void bank::display()
{
  cout<<"account number is : "<<acc_no << endl;
  cout<<"account holder is : "<<name << endl;
  cout<<"account type is : "<<type << endl;
  cout<<"account balance is : "<<balance << endl;
}

int main()
{
  int money;

  ofstream fout("account.dat",ios::app|ios::binary);
  ifstream fin("account.dat",ios::in|ios::binary);
  char ans='y';
  int ch;
  do{
    cout<<"\n          MAIN MENU        ";
    cout<<"\n 1]  add a record";
    cout<<"\n 2]  deposit money";
    cout<<"\n 3] withdraw money";
    cout<<"\n 4]  display all records";
    cout<<"\n Enter your choice";
    cin>>ch;
    switch(ch)
      {
      case 1:
      b.get();
      fout.write((char*)&b,sizeof(b));
      break;

      case 2:
            cout<<"enter the money to be deposited\n";
            cin>>money;
            b.deposit(money);
            break;

      case 3:
            cout<<"enter the money to be withdrawn\n";
            cin>>money;
            b.withdraw(money);
            break;

      case 4:
            while(fin.read((char*)&b,sizeof(b)))
            b.display();
            break;
      default:
        cout<<"\n Wrong choice......Try again!";
        break;
    }
    cout<<"\n Do you want to continue?(y/n)";
    cin>>ans;
    cin.ignore();
  }  while(ans=='y'||ans=='Y');

  fout.close();
  fin.close();
  return 0;
}
