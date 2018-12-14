#include <iostream>
#include <fstream>

using namespace std;

class Student
{
  int roll_no;
  char name[20];

 public:
   void get();
   void show();
   int get_roll_no()
   {
     return roll_no;
   }
};

void Student::get()
{
  cout<<"enter roll no : ";
  cin>>roll_no;
  cout<<"enter name : ";
  cin>>name;
}

void Student::show()
{
  cout<<"roll no : "<<roll_no<<endl;
  cout<<"name : "<<name<<endl;
}


int main()
{

  
  return 0;
}
