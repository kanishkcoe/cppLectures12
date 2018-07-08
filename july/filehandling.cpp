#include <iostream>
#include <fstream>

using namespace std;

class Student
{
  int roll;
  char name[20];

public:

  void get()
  {
    cout << "Enter roll number : ";
    cin >> roll;
    cin.ignore();

    cout << "Enter the name : ";
    cin.getline(name, 20);
  }

  void show()
  {
    cout << "Roll number : " << roll << endl;
    cout << "Name : " << name << endl;
  }

  int get_roll()
  {
    return roll;
  }
};

int main()
{
  // Student s[3];
  //
  // for(int i = 0; i < 3; i++)
  // {
  //   cout << "Student " << i + 1 << endl;
  //   s[i].get();
  // }
  //
  // ofstream fout;
  // fout.open("student.dat", ios::out | ios::binary);
  // for(int i = 0; i < 3; i++)
  // {
  //   fout.write((char *) &s[i], sizeof(s[i]));
  // }
  //
  // fout.close();


  //deletion of record
  ifstream mainfile;
  mainfile.open("student.dat", ios::in | ios::binary);

  if(!mainfile)
  {
    cout << "file doesn't exist." << endl;
    return 0;
  }

  Student s;

  int roll_number;
  cout << "Enter the  roll number to be deleted : ";
  cin >> roll_number;

  ofstream tempfile;
  tempfile.open("temp.dat", ios::out | ios::binary);


  while(!mainfile.eof())
  {
    mainfile.read((char*) &s, sizeof(s));
    if(roll_number != s.get_roll())
    {
      tempfile.write((char *) &s, sizeof(s));
    }
    else
    {
      continue;
    }
  }

  remove("student.dat");
  rename("temp.dat", "student.dat");

  tempfile.close();
  mainfile.close();
  return 0;
}
