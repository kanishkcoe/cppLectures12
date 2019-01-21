#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class bus
{
  int busno;
  char from[];
  char to[];
  char type;
  float fare;
  float distance;
public:
  bus()
  {
    type = 'O';
    fare = 500 ;
  }
    void calfare()
    {
      if(type == 'O')
      {
        fare = 15*distance;
      }
      if(type == 'E')
      {
        fare = 20*distance;
      }
      else
      {
        fare = 24*distance;
      }
    }

    void Register()
    {
      cout<<"enter busno"<<endl;
      cin>>busno;

      cout<<"enter from"<<endl;
      cin>>from;

      cout<<"enter to"<<endl;
      cin>>to;

      cout<<"enter type"<<endl;
      cin>>type;

      cout<<"enter distance = "<<endl;
      cin>>distance;

      calfare();
    }

    void showcabs()
    {
      cout<<" busno = "<<busno<<endl;

      cout<<" from = "<<from<<endl;

      cout<<" to = "<<to<<endl;

      cout<<" type = "<<type<<endl;

      cout<<" distance = "<<distance<<endl;

      cout<<"fare = "<<fare<<endl;

    }

};

int main()
{
  char y;
  bus c;
  do
{
  c.Register();
  c.showcabs();
  cout<<"do you want to continue = "<<endl;
  cin>>y;
}while(y == 'y');

  return 0;
}
