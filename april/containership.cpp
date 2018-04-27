#include <iostream>

using namespace std;

class Time
{
  int seconds;
  int minutes;
  int hours;

public:
  Time()
  {
    seconds = 0;
    minutes = 0;
    hours = 0;
  }

  void input();
  void output();
};

class Date
{
  int day;
  int month;
  int year;

  public:
  Time()
  {
    day = 0;
    month = 0;
    year = 0;
  }

  void input();
  void output();
};

void Time::input()
{
  cout << "Enter time(hh:mm:ss) : ";
  cin >> hours >> minutes >> seconds;
}

void Date::input()
{
  cout << "Enter date(dd:mm:yy) : ";
  cin >> day >> month >> year;
}

void Time::output()
{
  cout << hours << " : " << minutes << " : " << seconds;
}

void Date::output()
{
  cout << day << " : " << month << " : " << year;
}

class Player
{
  //using containership/aggregation
  
};

int main()
{


  return 0;
}
