#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Applicant
{
  long ANo;
  char name[20];
  float agg;
  char grade;
  void gradeMe()
  {
    if(agg >= 80)
    {
      grade = 'a';
    }

    else if(agg < 80 && agg >= 65)
    {
      grade = 'b';
    }

    else if(agg <65 && agg >= 50)
    {
      grade = 'c';
    }

    else
    {
      grade ='d';
    }


  }

public:
  void enter()
  {
    cout<<"enter admin no : ";
    cin>>ANo;
    cout<<"enter name : ";
    cin.ignore();
    cin.getline(name, sizeof(name));
    cout<<"enter marks : ";
    cin>>agg;
    gradeMe();

  }

  void result()
  {
    cout<<"admin no : "<<ANo<<endl;
    cout<<"name : "<<name<<endl;
    cout<<"marks : "<<agg<<endl;
    cout<<"grade : "<<grade<<endl;
  }
};

int main()
{
  Applicant a;
  a.enter();
  a.result();


  return 0;
}
