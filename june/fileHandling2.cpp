#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  char a[50];
  int count = 0;
  cout << "Enter any string : ";
  cin.getline(a, 50);

  //inserted item to the file
  ofstream fout;
  fout.open("test2.txt", ios::out);
  fout << a;
  fout.close();

  //getting item from the file
  ifstream fin;
  fin.open("test2.txt", ios::in);

  while(!fin.eof())
  {
    fin.getline(a, 50);
    cout << a << endl;
    // count++;
  }
  fin.close();
  // cout << count - 2 << endl;
  return 0;
}
