#include <iostream>

using namespace std;

////////////////////////////////////////

class Distance
{
private:
    int km;
    int m;

public:
    //constructors
    Distance(); //default constructor
    Distance(int, int); //parameterised constructor
    Distance(Distance &); //copy constructor

    //destructor
    ~Distance();
    //prototype
    void put_distance(void);
    void get_distance();
};


//defintions

Distance::Distance()
{
    km = 0;
    m = 0;
    //put_distance();
}

Distance::Distance(int a, int b = 1000)
{
    km = a;
    m = b;
}

Distance::Distance(Distance &t)
{
    km = t.km;
    m = t.m;
}

Distance::~Distance()
{
    //get_distance();
    cout << "Destructor called " << km << " == " << m << endl;
}

void Distance::put_distance(void)
{
    cout << "put function called" << endl;
    cout << "Enter distance : ";
    cout << "km = "; cin >> km;
    cout << "m = "; cin >> m;
}

void Distance::get_distance()
{
    cout << km << " km " << m << " m." << endl;
}


////////////////////////////////////////
int main()
{
    Distance d1;
    Distance d2;
    cout << "d2 : ";
    d2.get_distance();
    d2 = Distance(450, 123);
    Distance d3(56, 78);
    Distance d4(d2);
    Distance d5(340);
    Distance d6;

    // d.put_distance();
    d1.get_distance();
    d2.get_distance();
    d3.get_distance();
    d4.get_distance();
    d5.get_distance();
    d6.get_distance();
    return 0;
}
