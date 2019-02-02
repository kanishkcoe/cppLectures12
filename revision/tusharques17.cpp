#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void insert()
{
  int eno, salary;
  char choice , name[20], city[20], state[20], post[20];

  ofstream fout;
  fout.open("query.txt", ios::app);
  do
  {
    cout<<"enter eno"<<endl;
    cin>>eno;
    cout<<"enter name"<<endl;
    cin.ignore();
    cin.getline(name, sizeof(name));
    cout<<"enter salary"<<endl;
    cin>>salary;
    cout<<"enter city"<<endl;
    cin.ignore();
    cin.getline(city, sizeof(city));
    cout<<"enter state"<<endl;
    // cin.ignore();
    cin.getline(state, sizeof(state));
    cout<<"enter post"<<endl;
    // cin.ignore();
    cin.getline(post, sizeof(post));

    fout<<"INSERT INTO Employee( "<<eno<<", \""<<name<<"\", "<<salary<<", \""<<city<<"\", \""<<state<<"\", \""<<post<<"\");\n";
    // cout<<state<<endl<<post<<endl;

    cout<<"do you want to enter again"<<endl;
    cin>>choice;
 } while(choice == 'y');
 fout.close();

}

int main()
{
  insert();

  return 0;
}
