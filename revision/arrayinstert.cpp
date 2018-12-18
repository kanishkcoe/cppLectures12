#include<iostream>
#include<string.h>

using namespace std;

#define size 10

class Myarray
{
	int a[size];
	int n;

	public:
	void readArray();
	void printArray();
	int inselement(int);
};

void Myarray::readArray()
{

	  cout<<" how many elements   ";
	  cin>>n;
	  for(int i=0;i<n;i++)
		cin>>a[i];

}

void Myarray::printArray()
{
	  cout<<"\n";
	  for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
    cout << endl;
}

int Myarray::inselement(int e)
{
  int i;
  for(i = n - 1; a[i] > e; i--)
  {
    a[i+1] = a[i];
  }
  a[i+1] = e;
  n++;
}

int main()
{
  int pos=0;
  int num=0;
	Myarray ins;
	int ch;

	do
	{

    cout<<"\n MAIN MENU";
		cout<<"\n 1.	enter array";
		cout<<"\n 2.	display numbers";
		cout<<"\n 3.	insert the required element in the list";
      cout<<"\n 4.	quit";
		cout<<"\n\n enter your choice (1-4)   ";
		cin>>ch;

		switch(ch)
		{
			case 1:	ins.readArray();
						break;
			case 2:	ins.printArray();
						break;
			case 3:	cout<<"enter the element to be inserted\n";
          cin>>num;
          ins.inselement(num);
            break;
			case 4:	exit(0);
			default:	cout<<"wrong choice";
		}
	}while(ch != 4);


  return 0;
}
