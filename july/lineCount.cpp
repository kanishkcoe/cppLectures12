#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int countVowel(char *s)
{
  int count = 0;

  for(int i = 0; s[i] != NULL; i++)
  {
    switch(s[i])
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':

      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':count++;
      default : continue;
    }
  }

  return count;
}

int countUpper(char *s)
{
  int count = 0;

  for(int i = 0; s[i] != NULL; i++)
  {
    if(isupper(s[i]))
      count++;
  }

  return count;
}

int countWord(char *s)
{
  int count = 1;

  for(int i = 0; s[i] != NULL; i++)
  {
    if(s[i] == ' ')
      count++;
  }

  return count;
}


int countSpecial(char *s)
{
  int count = 0;

  for(int i = 0; s[i] != '\0'; i++)
  {
    if(!isalpha(s[i]) && s[i] != ' ')
      count++;
  }

  return count;
}

int main()
{
  ifstream file;
  file.open("poem.txt", ios::in);
  int lineCounter = 0;

  char line[100];
  int totalVowels = 0;
  while(file.getline(line, 100))
  {
    cout << line << endl;
    cout << "Uppers in line " <<  ++lineCounter  << " -> " << countWord(line) << endl;
    totalVowels += countVowel(line);
  }

  cout << lineCounter << endl;
  cout << totalVowels << endl;
  return 0;
}
