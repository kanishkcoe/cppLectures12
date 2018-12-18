#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

using namespace std;

class carrental
{
	long int carid;
	char aboutcar[20];
	char cartype[20];
	float rent;


public:
	float retrent() { return rent;}

	void assignrent()
	{
		if(strcmp(cartype,"small")== 0)
			rent=1000;
		else  if(strcmp(cartype,"van")== 0)
			rent=800;
		else  if(strcmp(cartype,"suv")== 0)
			rent=2500;


	}


		void getcar()
	{
		cout<<"enter car id : ";
		cin>>carid;

    cin.ignore();
		cout<<"\nenter something about car : ";
		gets(aboutcar);

    cout<<"\nenter type of car : ";
		gets(cartype);

		assignrent();
	}

	void showcar()
	{
		cout<<"car id no : "<<carid<<"\n"<<"about the car : "<<aboutcar<<endl;
		cout<<"type of car is : "<<cartype<<endl;
		cout<<"rent is : "<<rent<<endl;
	}
};

void write()
{
	carrental  c;
	ofstream fout;
	fout.open("CARRENTAL.DAT",ios::binary|ios::out);
	char reply;
	int i=0;

	do
	{
		i++;

		cout<<"enter record  "<<i<<" ";
		c.getcar();
		fout.write((char *)&c,sizeof(c));
		cout<<"\ndo u want to enter more records?\t";
		cin>>reply;

	}while(reply=='y' ||reply=='Y');
	fout.close();
}

void read()
{
	carrental  c;
	ifstream fin;
	fin.open("CARRENTAL.DAT",ios::binary|ios::in);
	int i=0;

	while(fin.read((char*)&c,sizeof(c)))
	{
		i++;

		cout<<" record no. "<<i<<" ";
		c.showcar();
	}

	fin.close();
}

void update()
{
	carrental c;

	fstream f;
	f.open("CARRENTAL.DAT",ios::binary|ios::in|ios::out);
	 int rec=0;
	 char found = 'n';

	while(f)
	{
		f.read((char*)&c,sizeof(c));
		if(c.retrent()== 2500 )
			{
			cout<<"enter new information\n";
			c.getcar();
			f.seekg(rec*sizeof(c),ios::beg);
			f.write((char*)&c,sizeof(c));
			found='y';
			break;
			}
		 rec++;
	}
	if (found=='y')
		cout<<"\n record updated ";
	else
		 cout<<"\n record not found ";
		 	f.close();

}


int main()
{
	int ch;
	do
	{
		// clrscr();
		cout<<"\n 1.	create file";
		cout<<"\n 2.	update ";
		cout<<"\n 3.	display  data";
		cout<<"\n 4.	quit";
		cout<<"\nenter your choice  : ";

		cin >>ch;

		switch(ch)
		{
			case 1:	write();
						break;
			case 2:	update();
						break;
			case 3:	read();
						break;
			//case 4:	exit(0);

			default:	cout<<"wrong choice";
		}
		// getch();
	}while(ch != 4);
return 0;
}
