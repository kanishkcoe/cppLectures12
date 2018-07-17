#include <iostream>

using namespace std;

class Test
{
  int *value;
  char *letter;

public:
  Test()
  {
    value = new int;
    letter = new char;
    *value = 0;
    *letter = '\0';
  }

  Test(int value, char letter)
  {
    this->value = new int;
    this->letter = new char;
    this->(*value) = value;
    this->(*letter) = letter;
  }

  Test(Test &t)
  {
    value = t.value;
    letter = t.let ter;
  }

  void get()
  {
    cout << "Enter value : "; cin >> *value;
    cout << "Enter letter : "; cin >> *letter;
  }

  void show()
  {
      cout << *value << " ===> " << *letter << endl;
  }

  ~Test()
  {
    cout << *value << " ===> " << *letter << endl;
    cout << "Destructor called! " << endl;
    delete value;
    delete letter;
  }
};
// struct Node
// {
//   int value;
//   char letter;
// };
//
// void createNodeAndShow(int val, char let)
// {
//   Node *temp;
//   temp = new Node;
//
//   temp->value = val;
//   temp->letter = let;
//
//   cout << temp->value << " ==> " << temp->letter << endl;
//
//   delete temp;
// }


// void swap(int *aptr, int *bptr)
// {
//   cout << "inside function : : " << endl;
//   cout << "aptr : " << aptr << ", bptr : " << bptr << endl;
//
//   int temp;
//   temp = *aptr;
//   *aptr = *bptr;
//   *bptr = temp;
//   cout << "outside function : : " << endl;
// }

int main()
{
  //pointer fundamentals
  // int x = 20;
  // cout << x << endl;
  //
  // int *xptr;
  // xptr = &x;
  // cout << xptr << endl;
  //
  // int **xpptr;
  // xpptr = &xptr;
  // cout << xpptr << endl;
  //
  //
  // int a = 5, b = 6;
  // int *aptr = &a, *bptr = &b;
  // cout << "aptr : " << aptr << ", bptr : " << bptr << endl;
  //
  // cout << "a : " << a << ", b : " << b << endl;
  // swap(aptr, bptr);
  // cout << "a : " << a << ", b : " << b << endl;


  //pointer arithmetics

  // int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // int *aptr;
  // aptr = &array[0];
  // cout << aptr << endl;
  // for(int i = 0; i < 10; i++)
  // {
  //   cout << *aptr << " ===> " << aptr << endl;
  //   aptr++;
  // }

  //dynamic allocation
  // int n;
  // cin >> n;
  // int array[n];
  // cout << "Enter elements : ";
  //
  //
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> array[i];
  // }
  //
  // for (int i = 0; i < n; i++)
  // {
  //   cout << array[i] << endl;
  // }


  // int size;
  // int *array;
  // cout << "Enter size of the array : "; cin >> size;
  // array = new int[size];
  // for (int i = 0; i < size-1; i++)
  // {
  //   cin >> array[i];
  // }
  //
  // for (int i = 0; i < size; i++)
  // {
  //   cout << array[i] << endl;
  // }
  //
  // delete [] array;



  //dynamic structures and classes



  // Node node;
  //
  // cout << "enter value : ";
  // cin >> node.value;
  // cin.ignore();
  // cout << "enter letter : ";
  // cin >> node.letter;
  //
  // cout << node.value << " ==> " << node.letter << endl;

  // createNodeAndShow(154, 'a');

  Test t(54, 'j');


  //this pointer





  return 0;
}
