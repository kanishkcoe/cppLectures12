#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Time
{
  int arrivalTime;
  int departureTime;
};

class Employee
{
private:
  int eno;
  char name[20];
  float salary;
  Time workTime;

public:
  //default constructor
  Employee()
  {
    eno = 0;
    strcpy(name, "undefined");
    salary = 0.0;
    workTime.arrivalTime = 0;
    workTime.departureTime = 0;
  }

  //parameterized constructor
  Employee(int num, char * naam, float sal, int arrival, int departure)
  {
    eno = num;
    strcpy(name, naam);
    salary = sal;
    workTime.arrivalTime = arrival;
    workTime.departureTime = departure;
  }

  //copy constructor
  Employee(Employee &employee)
  {
    eno = employee.eno;
    strcpy(name, employee.name);
    salary = employee.salary;
    workTime.arrivalTime = employee.workTime.arrivalTime;
    workTime.departureTime = employee.workTime.departureTime;
  }

  ~Employee()
  {
    cout << "destructor for employee " << eno << " called." << endl;
  }

  void get_details();
  void show_details();
};

void promotedemployee(Employee *);

int main()
{


  return 0;
}

void Employee::get_details()
{
  cout << "Enter employee number : "; cin >> eno;
  cin.ignore();
  cout << "Enter name : "; gets(name);
  cout << "Enter salary : "; cin >> salary;
  cout << "Enter arrival time and departure time : ";
  cin >> workTime.arrivalTime >> workTime.departureTime;
}

void Employee::show_details()
{
  cout << "---------------------------------------------------------------" << endl;
  cout << "Employee number : " << eno << endl;
  cout << "Employee name : " << name << endl;
  cout << "Salary : " << salary << endl;
  cout << "Work time : " << workTime.arrivalTime << " - " << workTime.departureTime << endl;
  cout << "---------------------------------------------------------------" << endl;
}

void promotedemployee(Employee *employee)
{
  //loop through all employees
  for(int i = 0; i < size; i++)
  {
    //if salary < 100000 and work hours > 7
    if(employee[i].salary < 100000 && employee[i].workingHours > 7)
    {
      //update salary = salary * 1.1
      employee[i].updateSalary();
      //display details
    }
  }
}
