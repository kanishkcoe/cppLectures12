#include<iostream>
#include<fstream>
using namespace std;
class stud
{
	int rno;
	char name[25];
	char cls[4];
	float marks;
	char grade;
	public:
		void getdata()
		{
			cout<<"\n Roll number: ";
			cin>>rno;
      cin.ignore();
			cout<<"\n Name: ";
			cin.getline(name,25);

      cout<<"\n Class: ";
      cin.getline(cls,4);
			cout<<"\n Marks: ";
      cin>>marks;
		}
		int retmarks()
    {
      return marks;
    }
    int retrno()
    {
      return rno;
    }

    //void insert();
    //void search(int );
    //void display();
    void putdata();
};

void insert(stud s)
{
  int flag = 0;
  ofstream fout("stud.dat",ios::app|ios::binary);

  s.getdata();
  if(s.retmarks()>90)
  {
    flag=1;
    fout.write((char*)&s,sizeof(s));
    cout<<"\n RECORD ADDED TO FILE";

  }
  if(!flag)
  cout<<"\n STUDENT NOT ELIGIBLE TO BE ADDED";
  fout.close();
}

void search(int roll)
{
  int found = 0;
  stud s;
  ifstream fin("stud.dat",ios::in|ios::binary);
  while(fin.read((char*)&s,sizeof(s)))
  {
    if(roll==s.retrno())
    {
      found = 1;
      s.putdata();
    }

    if(found==0)
    cout<<"\trecord not found\n";
  }
  fin.close();
}

void display()
{
  stud s;
  ifstream fin("stud.dat",ios::in|ios::binary);
  while(!fin.eof())
  {
    fin.read((char*)&s,sizeof(s));

      s.putdata();
  }
  fin.close();
}

void stud::putdata()
{
  cout<<"roll number is\t"<<rno;
  cout<<"\nstudent name is\t"<name;
  cout<<"\nstudent marks are\t"<<marks;
  cout<<"\nclass is\t"<<cls;
}


int main()
{
  int roll;
  stud s;
	char ans='y';
	while(ans=='y'||ans=='Y')
	{
		int ch;
		cout<<"\n          MAIN MENU        ";
		cout<<"\n 1]  add  record to the meritorous students";
    cout<<"\n 2]  search  record of a meritorous student";
		cout<<"\n 3]  display all the meritorous students";
		cout<<"\n Enter your choice";
    cin>>ch;
    switch(ch)
		{

			case 1: insert(s);
      break;
			case 2: cout<<"enter the roll number to be searched\n";
				      cin>>roll;
              search(roll);
      break;
      case 3: display();
			default:
				cout<<"\n Wrong choice......Try again!";
				break;
		}
		cout<<"\n Do you want to continue?";
		cin>>ans;
	}
  return 0;
}
