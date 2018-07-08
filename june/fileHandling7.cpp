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

  // for(int i = 0; i < 3; i++)
  // {
  //   cout << "Student " << i + 1 << endl;
  //   s[i].get();
  // }
  //
  // ofstream fout;
  // fout.open("sortedStud.txt", ios::out);
  // for(int i = 0; i < 3; i++)
  // {
  //   fout.write((char *) &s[i], sizeof(s[i]));
  // }
  //
  // fout.close();

  //reading objects from file
  // ifstream fin;
  // fin.open("test5.txt", ios::in);
  //
  // for(int i = 0; i < 3; i++)
  // {
  //   fin.read((char *) &s[i], sizeof(s[i]));
  //   cout << "Student " << i + 1 << endl;
  //   s[i].show();
  // }

  //main input
  Student input;
  Student s;
  input.get();

  ofstream tempfile;
  tempfile.open("temp.txt", ios::out);  //writing file

  ifstream mainfile;
  mainfile.open("sortedStud.txt", ios::in); //reading file

  while(!mainfile.eof())
  {
    mainfile.read( (char *) &s, sizeof(s));
    if(s.get_roll() < input.get_roll())
    {
      tempfile.write((char *) &s, sizeof(s));
    }
    else
    {
      tempfile.write((char *) &input, sizeof(input));
      break;
    }
  }

  while(!mainfile.eof())
  {
    mainfile.read( (char *) &s, sizeof(s));
    tempfile.write((char *) &s, sizeof(s));
  }

  remove("sortedStud.txt");
  rename("temp.txt", "sortedStud.txt");
  mainfile.close();
  tempfile.close();

  return 0;
}
