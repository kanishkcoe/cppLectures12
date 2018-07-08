#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include <iomanip>

using namespace std;

class Ticket
{
private:
  char flight[6];  //flight id
  char passenger[20];  //name of the passenger
  int id; //particular ID of the associated Ticket
  char to[4];  //destination  where this plane arrives
  char from[4]; //source location  from where the plane leaves
  double cost;
  void compute_cost(int, int); //computes the cost and initialises the flight name
public:
  void get(int); //gets the above mentioned data from the user
  int get_id(); //returns the ID of the ticket
  void print_ticket();
};

void Ticket::compute_cost(int choice_from, int choice_to)
{
  switch (choice_from)
  {
    case 1: strcpy(from, "MUM");
      break;
    case 2: strcpy(from, "DEL");
      break;
    case 3: strcpy(from, "KOL");
      break;
    case 4: strcpy(from, "CHE");
      break;
  }

  switch (choice_to)
  {
    case 1: strcpy(to, "MUM");
      break;
    case 2: strcpy(to, "DEL");
      break;
    case 3: strcpy(to, "KOL");
      break;
    case 4: strcpy(to, "CHE");
      break;
  }

  if(abs(choice_from - choice_to) == 1)
    cost = 10000.00;
  else if(abs(choice_from - choice_to) == 2)
    cost = 11000.00;
  else if(abs(choice_from - choice_to) == 3)
    cost = 12000.00;
}

int Ticket::get_id()
{
  return id;
}

void Ticket::get(int i)
{
	id = i;
  int choice1;
  do {
    system("cls");
    cout<<"from:"<<endl;
    cout<<"1.mumbai"<<endl;
    cout<<"2.delhi"<<endl;
    cout<<"3.kolkata"<<endl;
    cout<<"4.chennai"<<endl;
    cin>>choice1;
    cout<<endl;
  } while(choice1 <= 0 || choice1 > 4);


  int choice2;

  do
  {
    system("cls");
    cout<<"to:"<<endl;
    cout<<"1.mumbai"<<endl;
    cout<<"2.delhi"<<endl;
    cout<<"3.kolkata"<<endl;
    cout<<"4.chennai"<<endl;
    cin>>choice2;
    cout<<"pls input valid choice\n";
  }while(choice2==choice1);

  system("cls");
  cout<<"name:"<<endl;
  cin.ignore();
  cin.getline(passenger,20);
  system("cls");

  compute_cost(choice1, choice2);

  int choice3;
  do
  {
    system("cls");
    cout<<"flights:"<<endl;
    cout<<"1.jet airways"<<endl;
    cout<<"2.indigo"<<endl;
    cout<<"3.air india"<<endl;
    cout<<"4.etihad flights"<<endl;
    cin>>choice3;
    cout<<endl;
  }while(choice3 <= 0 || choice3 > 4);
  switch(choice3)
  {
    case 1: strcpy(flight, "JETAR");
      break;
    case 2: strcpy(flight, "INDGO");
      break;
    case 3: strcpy(flight, "AIRID");
      break;
    case 4: strcpy(flight, "ETIHD");
      break;
  }
}

void Ticket::print_ticket()//Train train , Journey journey,Customer customer,Station station)
{
  int clear;
  cout << "+----------------------------------------------------------------+" << endl;
  cout << "|                           TICKET                               |" <<endl;
  cout << "+----------------------------------------------------------------+" << endl;
  cout << "|passenger name :"<< setw(20) << passenger <<"                            |" << endl;
  cout << "|from           :"<< setw(4) << from << "                                            |" << endl;
  cout << "|to             :"<< setw(4) << to << "                                            |" << endl;
  cout << "+----------------------------------------------------------------+" << endl;
  cout << "|price          :Rs " << setw(6) << cost << "                                       |"<<endl;
  cout << "|Flight         :"<< setw(6) << flight <<"                                          |"<<endl;
  cout << "+----------------------------------------------------------------+" << endl;
  cout << "\n\n\n";
  cout << "Press 1 to continue : ";
  cin >> clear;
}

//function declarations
void menu();
void intro();
void check_ticket();
void cancel_ticket();
void book_ticket();

int main()
{
  int i;
  intro();
  cin >> i;

  int choice = 0;
  do
  {
      system("cls");
      menu();
      cin >> choice;

      switch (choice)
      {
        case 1: book_ticket();
          break;
        case 2: check_ticket();
          break;
        case 3: cancel_ticket();
          break;
      }

  } while(choice != 4);

  cout << "Thank YOU!" << endl;
  return 0;
}

void intro()
{
  cout<<"\t**************************************************\n";
  cout<<"\t\tC++ Project on AIRWAYS RESERVATION\n";
  cout<<"\t**************************************************\n";
  cout<<"\t\t\t\tBY:\n";
  cout<<"\t\t\t\tKUNAL GAUR\n";
  cout<<"\t\t\t\tTUSHAR AGARWAL\n";
}

void menu()
{
  cout<<"\t**************************************************\n";
  cout<<"\t\tINDIAN AIRWAYS REGISTRATION PORTAL\n";
  cout<<"\t**************************************************\n";
  cout<<"\t\t\t\tMENU\n";
  cout<<"\t\t\t----------------\n";
  cout<<"\t\t\t1.book ticket\n";
  cout<<"\t\t\t2.check ticket\n";
  cout<<"\t\t\t3.cancel ticket\n";
  cout<<"\t\t\t4.EXIT\n\n\n";
  cout<<"\t\t\tchoice: ";

}


void book_ticket()
{
    system("cls");
    Ticket ticket;
    int id = 1;
    ofstream fout;
    fout.open("Flight_details.dat", ios::app|ios::binary);
    if(!fout)
    {
      ticket.get(id);
      fout.write((char *) &ticket, sizeof(ticket));
      fout.close();
      cout << "your id is : " << id;
      return;
    }

  	Ticket temp;

   ifstream fin;
   fin.open("Flight_details.dat", ios::in | ios::binary);
	 fin.seekg(0, ios::beg);

   while(!fin.eof())
   {
      fin.read((char*)&temp, sizeof(temp));
   }
   id = temp.get_id() + 1;
   ticket.get(id);
   fout.write((char *) &ticket, sizeof(ticket));
   cout << "your id is : " << id;
   fout.close();
   fin.close();
}

void check_ticket()
{
  system("cls");
  ifstream fin;
  fin.open("Flight_details.dat", ios::in | ios::binary);


  if(!fin)
  {
    cout << "File doesn't exist please check!" << endl;
    return;
  }

  int ticket_id;
  cout << "Enter the ticket ID : ";
  cin >> ticket_id;

  Ticket ticket;

  while(!fin.eof())
  {
    fin.read((char*)&ticket, sizeof(ticket));
    if(ticket.get_id() == ticket_id)
    {
      ticket.print_ticket();
      break;
    }
  }
}


void cancel_ticket()
{
  system("cls");
  ifstream mainfile;
  mainfile.open("Flight_details.dat", ios::in | ios::binary);

  if(!mainfile)
  {
    cout << "file doesn't exist." << endl;
    return;
  }

  Ticket t;

  int ticket_id;
  cout << "Enter the ticket to be deleted : ";
  cin >> ticket_id;

  ofstream tempfile;
  tempfile.open("temp.dat", ios::out | ios::binary);


  while(!mainfile.eof())
  {
    mainfile.read((char*) &t, sizeof(t));
    if(ticket_id != t.get_id())
    {
      tempfile.write((char *) &t, sizeof(t));
    }
    else
    {
      continue;
    }
  }

  remove("Flight_details.dat");
  rename("temp.dat", "Flight_details.dat");

  tempfile.close();
  mainfile.close();
}
