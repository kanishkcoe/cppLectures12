#include <iostream>
#include <fstream>
#include<string.h>


using namespace std;

int ismidg(char word[])
{
  int mid;
  mid = (strlen(word) + 1)/2;
  if( strlen(word) % 2 != 0)
    {
      if(word[mid] == 'g')
       return 1;

    }
  return 0;
}

int midg()
{
  char word[20];
  int count = 0;

  //reading part
  ifstream file;
  file.open("file.txt", ios::in);


  while(file >> word)
  {
    if(ismidg(word))
      count++;
  }

  //remainder section of code

  file.close();
  return count;
}

int main()
{
  cout << midg() << endl;

  return 0;
}
