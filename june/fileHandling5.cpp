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
};

int main()
{

  Student s[3];

  //writing objects to file
  // for(int i = 0; i < 3; i++)
  // {
  //   cout << "Student " << i + 1 << endl;
  //   s[i].get();
  // }
  //
  // ofstream fout;
  // fout.open("test5.txt", ios::out);
  // for(int i = 0; i < 3; i++)
  // {
  //   fout.write((char *) &s[i], sizeof(s[i]));
  // }
  //
  // fout.close();

  //reading objects from file
  ifstream fin;
  fin.open("test5.txt", ios::in);

  for(int i = 0; i < 3; i++)
  {
    fin.read((char *) &s[i], sizeof(s[i]));
    cout << "Student " << i + 1 << endl;
    s[i].show();
  }

  return 0;
}
