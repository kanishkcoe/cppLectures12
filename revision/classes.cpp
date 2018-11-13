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
  char name[40];
  Date manufacture_date;
  Date expiry_date;
  float total_cost()
  {
    return price * quantity;
  }

public:
  Product()
  {
    //default constructor
    price = 10;
    quantity = 10;
    strcpy(id, "0000");
    strcpy(name, "none");
    manufacture_date.day = 10;
    manufacture_date.month = 10;
    manufacture_date.year = 10;
    expiry_date.day = 10;
    expiry_date.month = 10;
    expiry_date.year = 10;

  }
  Product(float p, char i[5], char n[40])
  {
    //parameterised constructor
    price = p;
    strcpy(id, i);
    strcpy(name, n);
    quantity = 10;
    manufacture_date.day = 10;
    manufacture_date.month = 10;
    manufacture_date.year = 10;
    expiry_date.day = 10;
    expiry_date.month = 10;
    expiry_date.year = 10;

  }
  Product(Product &object)
  {
    //copy constructor
    price = object.price;
    quantity = object.quantity;
    strcpy(id, object.id);
    strcpy(name, object.name);
    manufacture_date.day = object.manufacture_date.day;
    manufacture_date.month = object.manufacture_date.month;
    manufacture_date.year = object.manufacture_date.year;
    expiry_date.day = object.expiry_date.day;
    expiry_date.month = object.expiry_date.month;
    expiry_date.year = object.expiry_date.year;
  }
  void get();
  void show()
  {
    cout << "serial ID : ";
    cout << id;
    cout << endl;
    cout << "name : ";
    cout << name;
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
      cout << "fresh" << endl;
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


  ~Product()
  {
    cout << name << " is destructed. " << endl;
  }
};

void Product::get()
{
  cout << "Enter serial ID : ";
  cin.getline(id, sizeof(id));
  cin.ignore();
  cout << "Enter name : ";
  cin.getline(name, sizeof(name));
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

  Product product[3];
  Product product_1(120, "1200", "zero");
  Product product_2(product_1);

  product.show();
  product_1.show();
  product_2.show();
  return 0;
}
