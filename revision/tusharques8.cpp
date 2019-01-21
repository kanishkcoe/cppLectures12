#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class CABS
{
  int CNo;
  char type;
  float PKM;
  float dist;
public:
  CABS()
  {
    type = 'A';
    CNo = 111 ;
  }
    void charges()
    {
      if(type == 'A')
      {
        PKM = 25;
      }
      if(type == 'B')
      {
        PKM = 20;
      }
      else
      {
        PKM = 15;
      }
    }

    void Register()
    {
      cout<<"enter Cno"<<endl;
      cin>>CNo;

      cout<<"enter type"<<endl;
      cin>>type;

      charges();
    }

    void showcabs()
    {
      cout<<"enter distance = "<<endl;
      cin>>dist;

      cout<<"CNo = "<<CNo<<endl;
      cout<<"type = "<<type<<endl;
      cout<<"PKM = "<<PKM<<endl;
      cout<<"total amount = "<<PKM*dist<<endl;
    }

};

int main()
{
  char y;
  CABS c;
  do
{
  c.Register();
  c.showcabs();
  cout<<"do you want to continue = "<<endl;
  cin>>y;
}while(y == 'y');

  return 0;
}
