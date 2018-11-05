#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Date
{
  int day;
  int month;
  int year;
};

class Product
{
private:
  float price;
  int quantity;
  char id[5];
  Date manufacture_date;
  Date expiry_date;
  float total_cost()
  {
    return price * quantity;
  }

public:
  void get();
  void show()
  {
    cout << "serial ID : ";
    cout << id;
    cout << endl;
    cout << "quantity : ";
    cout << quantity;
    cout << endl;
    cout << "price : ";
    cout << price;
    cout << endl;
    cout << "date of maufacturing : ";
    cout << manufacture_date.day << "/" << manufacture_date.month << "/" << manufacture_date.year;
    cout << endl;
    cout << "date of expiry : ";
    cout << expiry_date.day << "/" << expiry_date.month << "/" << expiry_date.year;
    cout << endl;
    cout << "Total cost = " << total_cost() << endl;
  }

  void quality()
  {
    if(expiry_date.year - manufacture_date.year > 3)
    {
      cout << "stale" << endl;
    }
    else if(expiry_date.year - manufacture_date.year < 3)
    {
      cout << "fresh" 12<< endl;
    }
    else
    {
      if(expiry_date.month > manufacture_date.month)
      {
        cout << "fresh" << endl;
      }
      else if(expiry_date.month < manufacture_date.month)
      {
        cout << "stale" << endl;
      }
      else
      {
        if(expiry_date.day >= manufacture_date.day)
        {
          cout << "fresh" << endl;
        }
        else
        {
          cout << "stale" << endl;
        }
      }
    }
  }
};

void Product::get()
{
  cout << "Enter serial ID : ";
  cin >> id;
  cout << "Enter quantity : ";
  cin >> quantity;
  cout << "Enter price : ";
  cin >> price;
  cout << "Enter date of maufacturing : " << endl;
  cin >> manufacture_date.day >> manufacture_date.month >> manufacture_date.year;
  cout << "Enter date of expiry : " << endl;
  cin >> expiry_date.day >> expiry_date.month >> expiry_date.year;
}


int main()
{

  Product product;

  product.get();
  product.show();
  product.quality();
  return 0;
}
