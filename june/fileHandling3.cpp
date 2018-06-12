#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int upperCount(char * s)
{
  int count = 0;

  for(int i = 0; s[i] != NULL; i++)
  {
    if(isupper(s[i]))
    {
      count++;
    }
  }

  return count;
}

int lowerCount(char * s)
{
  int count = 0;

  for(int i = 0; s[i] != NULL; i++)
  {
    if(islower(s[i]))
    {
      count++;
    }
  }

  return count;
}

int main()
{
  char s[100];
  cout << "Enter your string : ";
  cin.getline(s, 100);

  ofstream fout;
  fout.open("test3.txt", ios::out | ios::nocreate);
  fout << s;

  // ifstream fin;
  // fin.open("test3.txt", ios::in);
  // fin.getline(s, 100);
  //
  // cout << s << endl;
  // cout << "Cap count : " << upperCount(s) << endl;
  // cout << "Lower count : " << lowerCount(s) << endl;
  //
  // fin.close();
  return 0;
}
