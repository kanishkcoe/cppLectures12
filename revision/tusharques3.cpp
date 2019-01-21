#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class circle
{
  float radius;
  float x;
  float y;

public:

  void get()
  {
    cout<<"enter the radius of circle : ";
    cin>>radius;
    cout<<"enter x and y coordinate of the circle : ";
    cin>>x>>y;
  }
  void area()
  {
    // cout<<"enter radius : "
    // cin>>radius;
    float area = (float)22/7 * radius * radius;
    cout<<"area is : "<<area<<endl;
  }

  void circumfrence()
  {
    // cout<<"enter radius : ";
    // cin>>radius;
    float circumfrence = 2 * (float)22/7 * radius;
    cout<<"circumfrence :"<<circumfrence<<endl;
  }
};

int main()
{
  circle c;
  c.get();
  c.area();
  c.circumfrence();

  return 0;
}
