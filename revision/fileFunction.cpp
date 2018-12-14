#include <iostream>
#include <fstream>

using namespace std;

class Student
{
  int roll_no;
  char name[20];

 public:
   void get();
   void show();
   int get_roll_no()
   {
     return roll_no;
   }
};

void Student::get()
{
  cout<<"enter roll no : ";
  cin>>roll_no;
  cout<<"enter name : ";
  cin>>name;
}

void Student::show()
{
  cout<<"roll no : "<<roll_no<<endl;
  cout<<"name : "<<name<<endl;
}



int main()
{
//   Student student[5];
//
//   ofstream fout;
//
//   fout.open("student.dat",ios::out);
//
//  for(int i=0;i<5;i++)
// {
//   student[i].get();
//   fout.write((char*) &student[i],sizeof(student[i]));
// }
//   fout.close();

  //1. find the second last object details

    Student student;
    ifstream file;

    file.open("student.dat",ios::in);
    //
    // // file.seekg(48);
    //
    // file.seekg(-2*sizeof(Student), ios::end);
    // //
    // file.read((char*) &student, sizeof(student));
    // // // file.read((char*) &student, sizeof(student));
    // // //
    // int pos = file.tellg();
    // // // //file.seekg(-pos, ios::cur);
    // // // //file.read((char*) &student, sizeof(student));
    // student.show();
    // // //
    // cout << pos << endl;
    //
    while(file.read((char*) &student, sizeof(student)))
    {
      if(student.get_roll_no() == 5)
      {
        cout << file.tellg() / sizeof(student)<< endl;
        student.show();
      }
    }

  //2. find the roll number of 3rd student

  // file.seekg(0, ios::end);
  // file.seekg(-1*sizeof(student), ios::cur);

   // student.show();
   file.close();
  //3. find position of roll number 77
  return 0;
}
