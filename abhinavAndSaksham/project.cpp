//saksham
#include <iostream>

using namespace std;

class Employee
{
    char designation[30];
    char name[30];
    char address[30];
    double salary;
    int Eno;
    Date dob;

    public:
        int get();
        int show();
        void RetEno()
        {
            return Eno;
        }

        Employee()
        {
            strcpy(designation,"Not defined");
            strcpy(name,"Not defined");
            strcpy(address,"Not defined");
            salary=0;
            Eno=0;
        }

};



void Employee::get()
{
    cout<<"enter details:"<<endl;

    cin.ignore();
    cout<<"\t\tenter designation\t\t"<<endl;
    cin.getline(designation,30);

    cin.ignore();
    cout<<"\t\tenter name:\t\t"<<endl;
    cin.getline(name,30);

    cin.ignore();
    cout<<"\t\tenter address\t\t"<<endl;
    cin.getline(address,30);

    cout<<"\t\tenter salary\t\t"<<endl;
    cin>>salary;

    cout<<"\t\tenter employee number\t\t"<<endl;
    cin>>Eno;

    cout<<"\t\tenter date of birth\t\t"<<endl;
    cin>>dob.date>>dob.month>>dob.year;
}

void Employee::show()
{
    cout<<"\t\tdesignation is:"<<designation<<endl;
    cout<<"\t\tname is:"<<name<<endl;
    cout<<"\t\taddress is:"<<address<<endl;
    cout<<"\t\tsalary is:"<<salary<<endl;
    cout<<"\t\temployee number is:"<<Eno<<endl;
    cout<<"\t\tdate of birth is:"<<dob.date<<dob.month<<dob.year<<endl;
}

struct Date
{
    int date=0;
    int month=0;
    int year=0;
};

int main()
{

    return 0;
}

//saksham







//kanishk
void menu();
void intro();

void menu()
{
  cout << "***************************************************************************" << endl;
  cout << "                            EMPLOYEE DATABASE                              " << endl;
  cout << "***************************************************************************" << endl;
  cout << "                         1. ADD EMPLOYEE RECORD                            " << endl;
  cout << "                         2. DELETE EMPLOYEE RECORD                         " << endl;
  cout << "                         3. MODIFY EMPLOYEE RECORD                         " << endl;
  cout << "                         4. SHOW EMPLOYEES LIST                            " << endl;
  cout << "                         5. SHOW EMPLOYEE RECORD                           " << endl;
  cout << "                         6.QUIT                                            " << endl;
  cout << "                         ENTER CHOICE : ";
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout<<"\n\n\n\t  EMPLOYEE";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : ABHINAV JAIN AND SAKSHAM MIDHA";
	//getch();
}


void modify_record()
{
  Employee existing;
  int enumber;

  cout << "Enter the employee number to be updated : ";
  cin >> enumber;

  ifstream mainfile;
  mainfile.open("records.dat", ios::in | ios::binary);

  if(!mainfile)
  {
    cout << "File doesn't exist! " << endl;
    return;
  }

  ofstream tempfile;
  tempfile.open("temp.dat", ios::out | ios::binary);

  while (!mainfile.eof())
  {
    mainfile.read((char*) &existing, sizeof(existing));

    if(existing.RetEno() == enumber)
    {
      existing.get();
      tempfile.write((char*) &existing, sizeof(existing));
    }
    else
    {
      tempfile.write((char*) &existing, sizeof(existing));
    }
  }

  remove("records.dat");
  rename("temp.dat", "records.dat");

}

void show_all()
{
  cout << "***************************************************" << endl;
  cout << "                EMPLOYEES' LIST" << endl;
  cout << "***************************************************" << endl;

  ifstream mainfile;
  mainfile.open("records.dat", ios::in | ios::binary);

  if(!mainfile)
  {
    cout << "File doesn't exist! " << endl;
    return;
  }

  Employee existing;

  while(!mainfile.eof())
  {
    mainfile.read((char*) &existing, sizeof(existing));

    cout << existing.RetEno() << " - " << existing.RetName() << endl;
  }
}


//kanishk



//abhinav

void add()
{

void add_employee()
{
  Employee e;
  e.get();
  ofstream mainfile;
  mainfile.open("records.dat",ios::app | ios::binary);
  mainfile.write((char*)&e, sizeof(e));

  mainfile.close();

}

void delete_employee()
{
  int e_number;
  cout<<"\t\tenter employee_number to be deleted\n";
  cin>>e_number;
  Employee em;
  em.get();
  ifstream mainfile;
  mainfile.open("records.dat",ios::in | ios::binary);

  ofstream tempfile;
  tempfile.open("temp.dat",ios::out | ios::binary);
  if(!mainfile)
  {
    cout<<"\t\tno records exist\n";
    return 0;
  }

  while(!mainfile.eof())
  {

    mainfile.read((char*)&em, sizeof(em));
    if(!e_number==Ret_eno())
    {
      tempfile.write((char*)&em, sizeof(em));

    }
    else continue;

  }
  remove("records.dat");
  rename("rename.dat","records.dat");

}




void show_particular()
{
  employee e;
  int enumber;
  cout<<"\t\tenter employee number to be shown\n";
  cin>>enumber;
  if(enumber==Ret_eno())
  {
    e.show();
  }
  employee.obj;
  obj.show()



}





//abhinav
