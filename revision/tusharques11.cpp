#include <iostream>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;

class Student
{
  int roll;
  char section;
  char name[20];
public:
  int getroll()
  {
    return roll;
  }

  void get()
  {
    cout<<"enter roll no : ";
    cin>>roll;

    cout<<"enter class :  ";
    cin>>section;

    cout<<"enter name : ";
    cin.ignore();
    cin.getline(name , sizeof(name));

  }

  void show()
  {
    cout<<"roll no "<<roll<<endl;
    cout<<"class  "<<section<<endl;
    cout<<"name  "<<name<<endl;
  }
};

void insertion()
{
  Student student , newstudent;

  ifstream mainfile;
  ofstream tempfile;

  mainfile.open("student.dat", ios:: in);
  tempfile.open("tempfile.dat" , ios::out);

  cout<<"enter data"<<endl;
  newstudent.get();

  while(mainfile.read((char*) &student , sizeof(student)))
{
  if(newstudent.getroll() > student.getroll())
  {
    tempfile.write((char*) &student , sizeof(student));
  }

  else
  {
    tempfile.write((char*) &newstudent , sizeof(newstudent));
    tempfile.write((char*) &student , sizeof(student));
    break;
  }
}

  while(mainfile.read((char*) &student , sizeof(student)))
 {
  tempfile.write((char*) &student , sizeof(student));
 }

 remove("student.dat");
 rename("temfile.dat" , "student.dat");

 mainfile.close();
 tempfile.close();
}

void deletion()
{
  Student student;
  int roll;
  ifstream mainfile;
  ofstream tempfile;

  mainfile.open("student.dat", ios:: in);
  tempfile.open("tempfile.dat" , ios::out);

  cout<<"enter roll"<<endl;
  cin>>roll;

while(mainfile.read((char*) &student , sizeof(student)))
{
  if(roll != student.getroll())
  {
    tempfile.write((char*) &student , sizeof(student));
  }

}
 remove("student.dat");
 rename("temfile.dat" , "student.dat");

 mainfile.close();
 tempfile.close();
}

void modification()
{
  Student student , newstudent;
  int roll;
  ifstream mainfile;
  ofstream tempfile;

  mainfile.open("student.dat", ios:: in);
  tempfile.open("tempfile.dat" , ios::out);

  cout<<"enter roll"<<endl;
  cin>>roll;

while(mainfile.read((char*) &student , sizeof(student)))
{
  if(roll != student.getroll())
  {
    tempfile.write((char*) &student , sizeof(student));
  }

  else
  {
    cout<<"enter new details"<<endl;
    newstudent.get();
    tempfile.write((char*) &newstudent , sizeof(newstudent));
  }

}
 remove("student.dat");
 rename("temfile.dat" , "student.dat");

 mainfile.close();
 tempfile.close();
}

void search()
{
  Student student , newstudent;
  int roll;
  ifstream mainfile;

  mainfile.open("student.dat", ios:: in);

  cout<<"enter roll"<<endl;
  cin>>roll;

while(mainfile.read((char*) &student , sizeof(student)))
{
  if(roll == student.getroll())
  {
    student.show();
  }

}

 mainfile.close();
}

int main()
{
  Student s;
  int n;

  ofstream mainfile;

  mainfile.open("student.dat" , ios::out);

  s.get();

  mainfile.write((char*) &s , sizeof(s));


  do
  {
    cout<<"enter choice"<<endl;
    cin>>n;

    cout<<"1.insert"<<endl;
    cout<<"2.delete"<<endl;
    cout<<"3.modify"<<endl;
    cout<<"4.search"<<endl;
    cout<<"5.exit"<<endl;

    switch (n)
    {
      case 1:insertion();
             break;

      case 2:deletion();
             break;

      case 3:modification();
             break;

      case 4:search();
             break;
    }

  } while(n!=5);

  return 0;
}
