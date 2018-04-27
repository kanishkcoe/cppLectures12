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
  Date()
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
  char name[20];
  int age;
  Time training_time;
  Date dob;
  Date doj;

public:
  void get();
  void put();
};

void Player::get()
{
  cin.ignore();
  cout << "Enter name : "; cin.getline(name, 20);
  cout << "Enter age : "; cin >> age;
  cout << "Enter training time : "; training_time.input();
  cout << "Enter DOB : "; dob.input();
  cout << "Enter DOJ : "; doj.input();
}

void Player::put()
{
  cout << "Name : " << name << endl;
  cout << "Age : " << age << endl;
  cout << "Training time : "; training_time.output(); cout << endl;
  cout << "DOB : "; dob.output(); cout << endl;
  cout << "DOJ : "; doj.output(); cout << endl;
}

int main()
{


  return 0;
}
