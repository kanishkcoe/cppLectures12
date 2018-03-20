#include <iostream>

using namespace std;

class Train
{
private:
  //data members
  int trainNo;  //train number
  int distance; //distance travelled by the train
  int fuel; //amount of fuel required at max
  float amount; //amount of ticket

  //private member functions
  void settleAmount();  //calculate the amount of ticket
  void settleFuel();  //calculate the fuel required

public:
  //member functions
  void getTicket();
  void showTicket();
};

//function definitions
void Train::getTicket()
{
  cout << "Enter train number : "; cin >> trainNo;
  cout << "Enter distance : "; cin >> distance;
  settleFuel();
  settleAmount();
}

void Train::settleFuel()
{
  if(distance <= 1500)
  {
    fuel = 250;
  }
  else if(distance > 1500 && distance <= 3000)
  {
    fuel = 1000;
  }
  else
  {
    fuel = 2500;
  }
}

void Train::showTicket()
{
  cout << "Train Number : " << trainNo << endl;
  cout << "Distance : " << distance << endl;
  cout << "Amount : " << amount << endl;
  cout << "Fuel capacity : " << fuel << endl;
}

void Train::settleAmount()
{
  if(distance <= 1000)
  {
    cout << "here";
    amount = float(distance * 0.5);
  }
  else if(distance > 1000 && distance <= 2000)
  {
    amount = float(distance * 0.4);
  }
  else if(distance > 2000 && distance <= 3000)
  {
    amount = float(distance * 0.3);
  }
  else
  {
    amount = float(distance * 0.2);
  }
}

int main()
{
  Train t;

  t.getTicket();
  t.showTicket();

  return 0;
}
