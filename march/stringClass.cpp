#include <iostream>
#include <string>

using namespace std;

int main()
{
  string name;
  name = "kanishk debnath";
  cout << name << endl;
  if(name.find("kan") != std::string::npos)
  {
    cout << "aaye haaye!" << endl;
  }
  return 0;
}
