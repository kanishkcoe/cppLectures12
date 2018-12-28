//menu driven resort application
//book rooms, show booking details
//apply discount as per booking price
//5 - 1000+
//10 - 2000+
//15 - 3000+
//20 - 4000+
//upto 10000
//create file to save booking details as well
#include<iostream>
#include<fstream>

using namespace std;

class Resort     // main class
{
  int room;
  int bookid;
  char name[20];
  float price;
  int members;

public:
  Resort()        //constructor
  {
    room = 0;
    price = 0;
  }

int get_bookid()
{
  return bookid;
}
  void getdata();
  void Price();
  int calcdiscount();
  void show();

};

void Resort::getdata()       //function to get data from the user
{
  cout<<"Enter booking id - "<<endl;
  cin>>bookid;
  cin.ignore();
  cout<<"Enter name of client - "<<endl;
  cin.getline(name , sizeof(name));
  cout<<"Room 1 = 200 per head"<<endl<<"Room 2 = 300 per head"<<endl<<"Room 3 = 400 per head"<<endl;

  do
  {
    cout<<"Enter the room you want - "<<endl;
    cin>>room;
  } while(room > 3 || room < 1);

  cout<<"Enter no of members - "<<endl
  ;
  cin>>members;

  Price();
  calcdiscount();
}

void Resort::Price()      // function to calculate price
{
  if(room == 1)
  {
    price = 200*members;
  }

  else if(room == 2)
  {
    price = 300*members;
  }

  else
  {
    price = 400*members;
  }

}

int Resort::calcdiscount()   // function to calculate price after discount
{
  float discount = 0;

  if(price >= 1000 && price < 2000)
  {
    discount = price*0.05;
  }

  else if(price >= 2000 && price < 3000)
  {
    discount = price*0.10;
  }

  else if(price >= 3000 && price < 4000)
  {
    discount = price*0.15;
  }

  else if (price > 4000)
  {
    discount = price*0.20;
  }

  if(discount> 10000)
  {
    discount=10000;
  }

  cout<<"congratulations you have been given a dicount of - Rs."<<discount<<endl;
  price -= discount;

}

void Resort::show()      //function to show details of each person
{
  cout<<"Booking id - "<<bookid<<endl;
  cout<<"Name - "<<name<<endl;
  cout<<"Room - "<<room<<endl;
  cout<<"Price - Rs. "<<price<<endl;
}

void bookroom()      // function to book room in the resort
{
  Resort resort;

  ofstream file;

  file.open("resort.dat" , ios::app | ios:: binary);

  resort.getdata();

  file.write((char*) &resort , sizeof(resort));

  file.close();

  cout<<"Your booking been done."<<endl;

 }

void update_booking()     // function to update a booking
{
   int id;

   Resort resort;
   Resort newresort;

   cout<<"Enter the booking id you want to update - "<<endl;
   cin>>id;

   ofstream tempfile;

   ifstream mainfile;

  mainfile.open("resort.dat" , ios::in | ios:: binary);

  tempfile.open("temp.dat" , ios::out | ios:: binary);

  while(mainfile.read((char*) &resort , sizeof(resort)))
  {

    if(resort.get_bookid() != id)
    {
      tempfile.write((char*) &resort , sizeof(resort));
    }

    else
    {
      resort.getdata() ;
      tempfile.write((char*) &resort , sizeof(resort));
    }

   }

   while(mainfile.read((char*) &resort , sizeof(resort)))
   {
       tempfile.write((char*) &resort , sizeof(resort));
   }

   remove("resort.dat");
   rename("temp.dat" , "resort.dat");

   mainfile.close();
   tempfile.close();

   cout<<"Your booking is been updated."<<endl;
  }

void delete_booking()   // function to cancel a booking
{
   Resort resort;

   int id;
   cout<<"Enter the booking id you want to delete."<<endl;
   cin>>id;

   ofstream tempfile;

   ifstream mainfile;

  mainfile.open("resort.dat" , ios::in | ios:: binary);

  tempfile.open("temp.dat" , ios::out | ios:: binary);

  while(mainfile.read((char*) &resort , sizeof(resort)))
  {
    if(resort.get_bookid() != id)
    {
      tempfile.write((char*) &resort , sizeof(resort));
    }
  }

  while(mainfile.read((char*) &resort , sizeof(resort)))
  {
      tempfile.write((char*) &resort , sizeof(resort));
  }

   remove("resort.dat");
   rename("temp.dat" , "resort.dat");

   mainfile.close();
   tempfile.close();

   cout<<"Your booking is been cancelled."<<endl;

}

void showdata() //function to show the details of all bookings
{
  Resort resort;

  ifstream mainfile;

 mainfile.open("resort.dat" , ios::in | ios::binary);

 while(mainfile.read((char*) &resort , sizeof(resort)))
 {
     resort.show();
 }
  mainfile.close();

}

int main()
{
  Resort resort;
  int choice;
do
{

  cout<<"_________________________MENU__________________________"<<endl;
  cout<<"1. Book room"<<endl;
  cout<<"2. Update booking"<<endl;
  cout<<"3. Cancel booking"<<endl;
  cout<<"4. Show all booking details"<<endl;
  cout<<"5. EXIT"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>choice;

  switch (choice)
  {
    case 1: bookroom();
            break;

    case 2: update_booking();
            break;

    case 3: delete_booking();
            break;

    case 4:cout<<"======================DETAILS=========================="<<endl;
           showdata();
           break;
  }

} while(choice !=5);

cout<<"_______________________THANK YOU_______________________";

}
