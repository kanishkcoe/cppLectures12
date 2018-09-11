#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

//word to word
int isThe(char * word)
{
  if(strcmp(word, "the") == 0 || strcmp(word, "The") == 0)
  {
    return 1;
  }

  return 0;
}

isD(char * word)
{
  int length = strlen(word);

  if(length % 2 == 0)
    return 0;

  int mid = length / 2;

  if(word[mid] == 'd' || word[mid] == 'D')
  {
    return 1;
  }

  return 0;
}

isG(char * word)
{
  int length = strlen(word);

  if(length % 2 == 0)
    return 0;

  int mid = length / 2;

  if(word[mid] == 'g' || word[mid] == 'G')
  {
    return 1;
  }

  return 0;
}

int main()
{
  int count = 0;

  ifstream fin;
  fin.open("test.txt", ios::in);

  char word[20];

  int i = 0;
  while(fin >> word)
  {
    if(isG(word) == 1)
    {
      cout << i << " - ";
      cout << word << endl;
      count++;
    }
    i++;
  }

  cout << endl << "Count of the is = " << count << endl;
  return 0;
}
