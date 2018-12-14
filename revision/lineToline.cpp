//template for line to line or character to character type questions of file handling
#include <iostream>
#include <fstream>

using namespace std;

void something(char * line)
{
  //question's logic
}

int main()
{
  char line[100];

  //reading part
  ifstream file;
  file.open("file.txt", ios::in);


  while(file.getline(line, sizeof(line)))
  {
    //logic code
    something(word);
  }

  //remainder section of code

  file.close();
  return 0;
}
