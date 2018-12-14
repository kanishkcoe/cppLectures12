//template for line to line or character to character type questions of file handling
#include <iostream>
#include <fstream>

using namespace std;

int notA()
{
  char line[100];
  int count = 0;

  //reading part
  ifstream file;
  file.open("notA.txt", ios::in);

  file.seekg(400,ios::beg);

  while(file.getline(line, sizeof(line)))
  {
    if(line[0] != 'A')
      count++;
  }

  //remainder section of code

  file.close();
  return count;
}

int main()
{
  cout << notA() << endl;
  return 0;
}
