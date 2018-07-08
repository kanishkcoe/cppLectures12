#include <iostream>
#include <fstream>

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

    return count;
  }


}

int main()
{


  return 0;
}
