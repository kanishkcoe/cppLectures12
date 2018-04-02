#include <iostream>

using namespace std;

class Time
{
private:
  int hr, min, sec;

public:
  Time()
  {
    hr=5;
    min=8;
    sec=6;
  }

  Time(int h, int m, int s)
  {
    hr=h;
    min=m;
    sec=s;
  }

  Time(Time &d)
  {
    hr=d.hr;
    min=d.min;
    sec=d.sec;
  }

  void set_time();
  void get_time();

};

void Time::set_time()
{
  cout<<"enter hour"<<endl;
  cin>>hr;
  cout<<"enter minutes"<<endl;
  cin>>min;
  cout<<"enter seconds"<<endl;
  cin>>sec;

}


void Time::get_time()
{
  cout<<hr<<":"<<min<<":"<<sec;
}

int main()
{

  Time a, b;
  Time e=a;

  Time c(3, 5, 8);
  //a.set_time();
  b.set_time();
  Time g(b);
  a.get_time();
  cout<<endl;

  b.get_time();
  cout<<endl;
  c.get_time();
  cout<<endl; 
  g.get_time();
  cout<<endl;
  e.get_time();
  return 0;

}
