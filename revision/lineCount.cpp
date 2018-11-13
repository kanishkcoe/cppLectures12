#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int count = 0;

  char line[80];

  char word[10];

  ifstream fin;

  fin.open("test.txt", ios::in);

  while(fin >> word)
  {
    cout << "word : " << word << endl;
    count++;
  }

  cout << count << endl;
  return 0;
}
