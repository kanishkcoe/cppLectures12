#include <iostream>
#include <fstream>

using namespace std;

void hisToHer(char *line)
{
  if((line[0] == 'h' || line[0] == 'H') && (line[1] == 'i' || line[1] == 'I') && (line[2] == 's' || line[2] == 'S'))
  {
    line[1] = 'e';
    line[2] = 'r';
  }

  for(int i = 3; line[i] != NULL; i++)
  {
    if(line[i] == ' ')
    {
      if((line[i+1] == 'h' || line[i+1] == 'H') && (line[i+2] == 'i' || line[i+2] == 'I') && (line[i+3] == 's' || line[i+3] == 'S'))
      {
        line[i+2] = 'e';
        line[i+3] = 'r';
      }
    }
  }
}


int countThreeLetterWords(char *line)
{
  int lastSpaceIndex = 0;
  int count = 0;
  if(line[3] == ' ')
  {
    count++;
    lastSpaceIndex = 3;
  }

  for(int i = 4; line[i] != NULL; i++)
  {
    if(line[i] == ' ')
    {
      if((i - lastSpaceIndex) == 4)
      {
        count++;
      }
      lastSpaceIndex = i;
    }
  }
  return count;
}


int main()
{
  ifstream fin;
  fin.open("notes.txt", ios::in);

  char text[100];
  fin.getline(text, sizeof(text));

  hisToHer(text);

  cout << text << endl;
  cout << countThreeLetterWords(text) << endl;
  fin.close();

  ofstream fout;
  fout.open("notes.txt", ios::out);
  fout << text;
  fout.close();
  return 0;
}
