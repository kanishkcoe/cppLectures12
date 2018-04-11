#include <iostream>
using namespace std;

class Resort
{
private:
  int rno;
  char name[20];
  float charges;
  int days;
  float compute();

public:
  void getinfo();
  void dispinfo();
};

float Resort::compute()
{
  return days * charges;
}

void Resort::getinfo()
{
  //char buffer[2];
  cout << "Enter room number : ";
  cin >> rno;
  //cin.getline(buffer, 2);
  cin.ignore();
  cout << "Enter name : ";
  cin.getline(name, 20);
  cout << "Enter number of days : ";
  cin >> days;
  cout << "Enter charges per day : ";
  cin >> charges;
}

void Resort::dispinfo()
{
  cout << "Room number : " << rno << endl;
  cout << "Name : " << name << endl;
  cout << "Days : " << days << endl;
  cout << "Charges per day : " << charges << endl;
  cout << "Total amount : " << compute() << endl;
}

int main()
{
  Resort r;

  r.getinfo();
  r.dispinfo();

  return 0;
}
