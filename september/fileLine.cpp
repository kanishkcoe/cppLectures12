#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int isAorI(char * line)
{
  if(line[0] == 'a' || line[0] == 'A')
    return 1;

  if(line[0] == 'i' || line[0] == 'I')
    return 1;

  return 0;
}

int main()
{
  int count = 0;

  ifstream fin;
  fin.open("test.txt", ios::in);

  char line[100];

  int i = 1;
  while(fin.getline(line, sizeof(line)))
  {
    if(isAorI(line) == 1)
    {
      cout << i << " - " << line << endl;
      count++;
    }
    i++;
  }

  cout << endl << "Count is = " << count << endl;
  return 0;
}
