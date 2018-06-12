#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int a;
  cout << "Enter any integer : ";
  cin >> a;

  //inserted item to the file
  ofstream fout;
  fout.open("test1.txt", ios::out);
  fout << a;
  fout.close();

  //getting item from the file
  ifstream fin;
  fin.open("test1.txt", ios::in);
  fin >> a;
  fin.close();

  cout << a;
  return 0;
}
