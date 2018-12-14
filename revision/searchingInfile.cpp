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
  //search data of given roll number
  int r;
  cout << "Enter roll number : ";
  cin >> r;

  int flag = 0;

  Student student;

  ifstream fin;

  fin.open("student.dat", ios::in);

  while (fin.read((char *) &student, sizeof(student)))
  {
    if(student.get_roll_no() == r)
    {
      flag = 1;
      student.show();
    }
  }

  if(!flag)
  {
    cout << "no such roll_no." << endl;
  }
  fin.close();
  return 0;
}
