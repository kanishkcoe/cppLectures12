#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

struct Date
{
  int date;
  int month;
  int year;
};


class Employee
{
    char designation[30];
    char name[30];
    char address[30];
    double salary;
    int Eno;
    Date dob;

    public:
	void get();
	void show();
	int RetEno()
	{
	    return Eno;
	}
	char * RetName()
	{
		return name;
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

//***************************************************************
//    	FUNCTION TO GET EMPLOYEE DETAILS
//****************************************************************
void Employee::get()
{
  cout<<"enter details:"<<endl;

  cin.ignore();
  cout<<"\t\tenter designation: ";
  cin.getline(designation,30);

  cin.ignore();
  cout<<"\t\tenter name: ";
  cin.getline(name,30);

  cin.ignore();
  cout<<"\t\tenter address: ";
  cin.getline(address,30);

  cin.ignore();
  cout<<"\t\tenter salary: ";
  cin>>salary;

  cin.ignore();
  cout<<"\t\tenter employee number: ";
  cin>>Eno;

  cin.ignore();
  cout<<"\t\tenter date of birth(dd/mm/yyyy): ";
  cin>>dob.date>>dob.month>>dob.year;
}


//*************************
//FUNCTION TO SHOW EMPLOYEE DETAILS
//*************************
void Employee::show()
{
  cout<<"\t\tdesignation is:"<<designation<<endl;
  cout<<"\t\tname is:"<<name<<endl;
  cout<<"\t\taddress is:"<<address<<endl;
  cout<<"\t\tsalary is:"<<salary<<endl;
  cout<<"\t\temployee number is:"<<Eno<<endl;
  cout<<"\t\tdate of birth is:"<<dob.date<<dob.month<<dob.year<<endl;
}

//***************************************************************
//    	FUNCTIONS
//****************************************************************
void add_employee();
void delete_employee();
void modify_record();
void show_particular();
void show_all();
void menu();
void intro();
void modify_record();

//***************************************************************
//    	MAIN FUNCTION
//****************************************************************
int main()
{
    clrscr();
    intro();
    int choice;
    getch();
    do
    {
      clrscr();
      menu();
      cin >> choice;

      switch(choice)
      {
	case 1: add_employee();
	  getch();
	  break;
	case 2: delete_employee();
	  getch();
	  break;
	case 3: modify_record();
	  getch();
	  break;
	case 4: show_all();
	  getch();
	  break;
	case 5: show_particular();
	  getch();
	  break;

      }

    } while(choice != 6);

  cout << "\t\t\t\tTHANK YOU!" << endl;
  getch();
  return 0;
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
  cout<<"\n\n\n\t\t\t\t  EMPLOYEE";
  cout<<"\n\n\t\t\t\tMANAGEMENT";
  cout<<"\n\n\t\t\t\t  SYSTEM";
  cout<<"\n\n\n\n\t\t  MADE BY : ABHINAV JAIN AND SAKSHAM MIDHA";
  //getch();
}

//***************************************************************
//    	MENU FUNCTION
//****************************************************************
void menu()
{
  cout << "***************************************************************************" << endl;
  cout << "                            EMPLOYEE DATABASE                              " << endl;
  cout << "***************************************************************************" << endl;
  cout << "                         1. ADD EMPLOYEE RECORD                            " << endl;
  cout << "                         2. DELETE EMPLOYEE RECORD                         " << endl;
  cout << "                         3. MODIFY EMPLOYEE RECORD                         " << endl;
  cout << "                         4. SHOW EMPLOYEES LIST                            " << endl;
  cout << "                         5. SHOW PARTICULAR EMPLOYEE RECORD                           " << endl;
  cout << "                         6.QUIT                                            " << endl;
  cout << "                         ENTER CHOICE : ";
}




//***************************************************************
//    	FUNCTION TO ADD EMPLOYEE DETAILS
//****************************************************************
void add_employee()
{
  Employee e;
  e.get();
  ofstream mainfile;
  mainfile.open("records.dat",ios::app | ios::binary);
  mainfile.write((char*)&e, sizeof(e));

  mainfile.close();

}



//***************************************************************
//    	FUNCTION TO DELETE EMPLOYEE DETAILS
//****************************************************************
void delete_employee()
{
  int e_number;
  char choice;
  int deleted = 0;

  cout<<"\t\tenter employee_number to be deleted : ";
  cin>>e_number;

  Employee em;

  ifstream mainfile;
  mainfile.open("records.dat",ios::in | ios::binary);

  ofstream tempfile;
  tempfile.open("temp.dat",ios::out | ios::binary);

  if(!mainfile)
  {
    cout<<"\t\tno records exist\n";
    return;
  }
  mainfile.read((char*)&em, sizeof(em));
  while(!mainfile.eof())
  {
    if(e_number == em.RetEno())
    {
      em.show();
      cout << "Do you really want to delete this record?" << endl;
      cin >> choice;
      if(choice == 'n' || choice == 'N')
	tempfile.write((char*)&em, sizeof(em));
      else
      {
	deleted = 1;
      }

    }
    else
    {
	tempfile.write((char*)&em, sizeof(em));
    }
    mainfile.read((char*)&em, sizeof(em));
  }


  mainfile.close();
  tempfile.close();

  remove("records.dat");
  rename("temp.dat", "records.dat");
  if(deleted == 1)
  {
	cout << "Record deleted!" << endl;
  }
}


//***************************************************************
//    	FUNCTION TO MODIFY RECORDS
//****************************************************************
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
  mainfile.read((char*) &existing, sizeof(existing));
  while (!mainfile.eof())
  {


    if(existing.RetEno() == enumber)
    {
      cout << "Current data : " << endl;
      existing.show();

      existing.get();
      tempfile.write((char*) &existing, sizeof(existing));
    }
    else
    {
      tempfile.write((char*) &existing, sizeof(existing));
    }
    mainfile.read((char*) &existing, sizeof(existing));
  }

  mainfile.close();
  tempfile.close();
  remove("records.dat");
  rename("temp.dat", "records.dat");

}


//***************************************************************
//    	FUNCTION TO SHOW ALL EMPLOYEE NUMBERS AND NAMES
//****************************************************************
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

  mainfile.read((char*) &existing, sizeof(existing));
  while(!mainfile.eof())
  {
    cout << existing.RetEno() << " - " << existing.RetName() << endl;
    mainfile.read((char*) &existing, sizeof(existing));
  }
  mainfile.close();
}



//***************************************************************
//    	FUNCTION TO SHOW PARTICULAR EMPLOYEE NUMBER AND NAME
//****************************************************************
void show_particular()
{
  ifstream mainfile;
  mainfile.open("records.dat", ios::in | ios::binary);

  if(!mainfile)
  {
    cout << "File doesn't exist! " << endl;
    return;
  }

  Employee existing;
  int enumber;

  cout << "Enter the employee number to be updated : ";
  cin >> enumber;


  mainfile.read((char*) &existing, sizeof(existing));
  while(!mainfile.eof())
  {
    if(enumber == existing.RetEno())
	existing.show();

    mainfile.read((char*) &existing, sizeof(existing));
  }

}
