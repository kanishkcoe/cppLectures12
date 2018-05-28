#include <iostream>

using namespace std;

//train class defines details about the respective trains
class Train
{
private:
  char type;  //type of train (AC/NON-AC)
  char name[30];  //name of the Train
  int id; //particular ID of the associated Train
  char destination[4];  //destination code where this train arrives
  char source[4]; //source location code frome where the train leaves
  int number_of_coaches;  //gives the number of coaches for cost and seat availability
  float speed;  //tells the speed of the train for cost calculation

public:
  void get(); //gets the above mentioned data from the user
  void show_type(); //returns the type of the train
  void show_name(); //returns the name of the train
  void show_id(); //returns the ID of the train
  void show_destination(); //returns the destination location code of the train
  void show_source(); //returns the source location code of the train
  void show_number_of_coaches(); //returns the number of coaches of the train
  void show_speed(); //returns the speed of the train
};

//Customer class gives details about the customer
class Customer
{
private:
  int age;  //age of the customer
  char name[20];  //name of the customer

public:
  void get();  //get details of the customer
  void show_name();  //returns name of the customer
  void show_age();  //returns age of the customer
};

int main()
{


  return 0;
}
