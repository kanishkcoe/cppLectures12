#include <iostream>
#include <fstream>
#include <stdio.h>

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
  Student student;
  Student tempstud;
  //
  // cout << "Enter data : " << endl;
  // tempstud.get();


  ifstream fin;
  ofstream fout;

  fin.open("temp.dat", ios::in);

  // fout.open("temp.dat", ios::out);

  while (fin.read((char *) &student, sizeof(student)))
  {
      student.show();
  }


  // while (fin.read((char *) &student, sizeof(student)))
  // {
  //   if(tempstud.get_roll_no() > student.get_roll_no())
  //   {
  //     //write from existing file
  //     fout.write((char *) &student, sizeof(student));
  //   }
  //   else if(tempstud.get_roll_no() < student.get_roll_no())
  //   {
  //     fout.write((char *) &tempstud, sizeof(tempstud));
  //     fout.write((char *) &student, sizeof(student));
  //     break;
  //   }
  // }
  //
  // while (fin.read((char *) &student, sizeof(student)))
  // {
  //     fout.write((char *) &student, sizeof(student));
  // }
  //
  //
  // remove("student.dat");
  //
  // rename("temp.dat", "student.dat");


  fin.close();
  fout.close();
  return 0;
}
