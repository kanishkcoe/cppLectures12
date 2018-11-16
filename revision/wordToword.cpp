//template for word to word type questions of file handling
#include <iostream>
#include <fstream>

using namespace std;

void something(char * word)
{
  //question's logic
}

int main()
{
  char word[20];

  //reading part
  ifstream file;
  file.open("file.txt", ios::in);


  while(file >> word)
  {
    //logic code
    something(word);
  }

  //remainder section of code

  file.close();
  return 0;
}
