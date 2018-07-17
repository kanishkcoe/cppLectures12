#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

int countDigit(char *line)
{
  int count = 0;

  for(int i = 0; line[i] != NULL; i++)
  {
    if(isdigit(line[i]))
      count++;
  }

  return count;
}

int main()
{
  char input[100];
  cout << "Enter your text : " << endl;
  cin.getline(input, sizeof(input));

  ofstream fout;
  fout.open("text.txt", ios::out);
  fout << input;
  fout.close();


  ifstream fin;
  fin.open("text.txt", ios::in);

  char line[100];
  int totalDigits = 0;
  int lineCounter = 0;
  int cd = 0;

  while (fin.getline(line, sizeof(line)))
  {
    cd = countDigit(line);
    totalDigits += cd;
    cout << ++lineCounter << " : " << cd << endl;
  }

  cout << "Total number of digits = " << totalDigits << endl;
  fin.close();
  return 0;
}
