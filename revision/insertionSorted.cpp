#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Employee
{
  int eno;
  char name[20];

public:
  void get()
  {
    cout << "Enter eno : ";
    cin >> eno;
    cout << "Enter name : ";
    cin.ignore();
    cin.getline(name, 20);
  }

  void show()
  {
    cout << "eno : ";
    cout << eno << endl;
    cout << "name : ";
    cout << name << endl;
  }

  int get_eno()
  {
    return eno;
  }
};

void insertsorted(Employee input)
{
   Employee s;

  ifstream mainfile;

  mainfile.open("stud.dat", ios::in);

  ofstream temp;

  temp.open("temp.dat", ios::out);

  while(mainfile.read((char*) &s, sizeof(s)))
  {
    if(s.get_eno()<input.get_eno())
    {
      temp.write((char*) &s, sizeof(s));
    }
    else
    {
      temp.write((char*) &input ,sizeof(input));
      temp.write((char*) &s ,sizeof(s));
      break;
    }
  }
  while(mainfile.read((char*) &s, sizeof(s)))
  {
    temp.write((char*) &s, sizeof(s));
  }

  remove("stud.dat");
  rename("temp.dat" , "stud.dat");

  mainfile.close();
  temp.close();
}

int main()
{
  // Employee emp;
  //
  // int n;
  //
  //
  // ofstream fout;
  //
  // fout.open("stud.dat", ios::out);
  //
  // cout << "Enter number of Employees to insert : ";
  // cin >> n;
  //
  // for(int i = 0; i < n; i++)
  // {
  //   emp.get();
  //   fout.write((char * ) &emp, sizeof(emp));
  // }
  //
  // fout.close();

  //reading
  // ifstream fin;
  // fin.open("stud.dat", ios::in);
  //
  //
  // cout << "Now the file has : " << endl;
  // while(fin.read((char * ) &emp, sizeof(emp)))
  // {
  //   cout << "---------------------------------" << endl;
  //   emp.show();
  //   cout << "---------------------------------" << endl;
  // }

  //create input object
   Employee input,emp;
  //get data for input
   input.get();
  //call insertSorted(input)
  insertsorted(input);

  //read the file again
  ifstream fin;
  fin.open("temp.dat", ios::in);

  while(fin.read((char * ) &emp, sizeof(emp)))
  {
    cout << "---------------------------------" << endl;
    emp.show();
    cout << "---------------------------------" << endl;
  }

  return 0;
}
