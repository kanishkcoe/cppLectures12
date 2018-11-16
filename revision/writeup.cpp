#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>

using namespace std;

int isTower(char * word)
{
  if(strcmp(word, "tower") == 0)
    return 1;
  else
    return 0;
}

int tower()
{
  char word[20];
  int count = 0;

  //reading part
  ifstream file;
  file.open("file.txt", ios::in);


  while(file >> word)
  {
    if(strcmp(word, "tower") == 0)
      count++;
  }

  //remainder section of code

  file.close();
  return count;
}

int main()
{
  cout << tower() << endl;

  return 0;
}
