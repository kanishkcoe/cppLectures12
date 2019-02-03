#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int createfile()
{
  char txt[100],c = 'y';
  cout<<"enter your txt"<<endl;
  ofstream fout;
  fout.open("joy.txt" , ios::out);
  while(c != 'n')
  {
    cin.getline(txt , sizeof(txt));
    fout<<txt;
    fout<<"\n";
    cout <<"want to enter more ? ";
    cin >> c;
    cin.ignore();
  }
  fout.close();
  return 0;
}

int countvowels()
{
  char line[100];
  int count=0;
  ifstream file;
  file.open("joy.txt" , ios::in);
  if(!file)
  {
    cout<<"here"<<endl;
  }
  while(file.getline(line , sizeof(line)))
  {
    cout<<line<<endl;
    for(int i=0 ; line[i] != NULL;i++)
    {
      if(line[i] == 'a' || line[i] == 'A'||line[i] == 'E'||line[i] == 'e'||line[i] == 'I'||line[i] == 'i'||line[i] == 'O'||line[i] == 'o'||line[i] == 'U'||line[i] == 'u')
      {
        count++;
      }
    }
  }
  file.close();
  cout<<"count = "<<count<<endl;
  return 0;
}
int countjoy()
{
  char word[20];
  int count=0;
  ifstream file;
  file.open("joy.txt" , ios::in);
  while(file >> word)
  {
    if(strcmp(word , "joy"))
    {
      count++;
    }
  }
  file.close();
  cout<<"count = "<<count<<endl;
  return 0;
}
int countline()
{
  char line[100];
  int count=0;
  ifstream file;
  file.open("joy.txt" , ios::in);
  while(file.getline(line , sizeof(line)))
  {
      if(line[0] == 'A')
      {
        count++;
      }

  }
  file.close();
  cout<<"count = "<<count<<endl;
  return 0;
}
int main()
{
  int choice;
 createfile();
do
{
  cout<<"1.count vowels"<<endl;
  cout<<"2.count joy"<<endl;
  cout<<"3.count line with a"<<endl;
  cout<<"4.exit"<<endl;
  cout<<"enter choice"<<endl;
  cin>>choice;

  switch(choice)
  {
    case 1:countvowels();
            break;
    case 2:countjoy();
            break;
    case 3:countline();
            break;
  }
}while (choice!= 4);
  return 0;
}
