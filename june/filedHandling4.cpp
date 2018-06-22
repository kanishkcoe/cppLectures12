#include <iostream>
#include <fstream>

using namespace std;

struct Employee
{
  int eno;
  char name[20];
  float salary;
};

int main()
{
  int num;
  Employee e[10];

  // cout << "Enter the number of details you want to enter : ";
  // cin >> num;
  //
  // for(int i = 0; i < num; i++)
  // {
  //   cout << "Enter eno : "; cin >> e[i].eno;
  //   cin.ignore();
  //   cout << "Enter name : "; cin.getline(e[i].name, 20);
  //   cout << "Enter salary : "; cin >> e[i].salary;
  // }

  // fstream fout;
  //
  // fout.open("test4.txt", ios::out);
  // // file.write((char *) & object, sizeof(object));
  //
  // for(int i = 0; i < num; i++)
  // {
  //   fout.write((char *) & e[i], sizeof(e[i]));
  // }
  //
  // fout.close();

  ifstream fin;
  fin.open("test4.txt", ios::in);

  for(int i = 0; i < 3; i++)
  {
    fin.read((char *) & e[i], sizeof(e[i]));
    cout << e[i].eno << " - " << e[i].name << " - " << e[i].salary << endl;
   }



  return 0;
}
