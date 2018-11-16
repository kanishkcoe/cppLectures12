#include<iostream>
#include<fstream>
#include <string.h>

using namespace std;

int isyou_and_me(char * word)
{
  if(strcmp(word,"you") == 0 || strcmp(word,"me") == 0)
    return 1;
  else
    return 0;
}

int you_and_me()
{
  char word[20];
   int count=0;

  ifstream file;
  file.open("story.txt",ios::in);

  while(file >> word)
  {
    if(isyou_and_me(word))
    count++;
  }

file.close();

return count;

}

int main()
{
  cout<<you_and_me()<<endl;
}
