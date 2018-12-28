#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
  char data;
  Node *next;
};

class Stack
{
  Node *top;
public:
  Stack()
  {
    top = NULL;
  }

  void push(char x)
  {
    Node *temp;
    temp = new Node;
    temp -> next = NULL;
    temp -> data = x;

    if (top == NULL)
    {
      // cout<<"here" << endl;
      top = temp;
      return;
    }

    else
    {
      temp -> next = top;
      top = temp;
    }
  }

  char pop()
  {
    char x;
    x = top -> data;
    Node *temp;

    if(top == NULL)
    {
      return NULL;
    }

    temp = top;
    top = top -> next;

    delete temp;
    return x;
  }

  int isempty()
  {
    if(top == NULL)
    {
      return 1;
    }

    return 0;
  }

  char peak()
  {
    char x = top -> data;

    return x;
  }

  void show()
  {
    Node *p;

    p = top;

    cout << "------" << endl;
    while(p != NULL)
    {
      cout << p -> data << endl;
      p = p -> next;
    }
    cout << "------" << endl;
  }
};

int precedence(char symbol)
{
  switch (symbol)
  {
    case '+' : return 1;
    case '-' : return 1;
    case '*' : return 2;
    case '/' : return 2;
    case '^' : return 3;
  }
}

void infixtopostfix(char input[])
{
  char output[50];
  int k = 0 ;
  Stack stack;

  char scan;

  cout << strlen(input) << endl;

  for(int i=0 ; i < strlen(input); i++)
  {

    cout << "\nstack position " << endl;
    stack.show();

    scan = input[i];

    //cout<<scan;
    if(isalpha(scan))
    {
      output[k++] = scan;
      //continue;
    }

    else if(stack.isempty() == 1)
    {
      stack.push(scan);
      //continue;
    }
    else if(stack.peak() == '(')
    {
      stack.push(scan);
    }
    else if(scan == '(')
    {
      stack.push(scan);
      //continue;
    }

    else if(scan == ')')
    {

      while(stack.peak() != '(')
      {
        //cout << stack.peak() << endl;
        output[k++] = stack.pop();
        //cout << output << endl;//////////////////////////
        //cout << stack.peak() << endl;
      }

      stack.pop();
      //cout << "here" << endl;

    }

    else if(precedence(stack.peak()) < precedence(scan))
    {
      // cout << "here1" << endl;
      stack.push(scan);
      //continue;
    }
    else
    {
      while(precedence(stack.isempty() != 1 && stack.peak()) >= precedence(scan))
      {
        output[k++] = stack.pop();
      }

     stack.push(scan);
    }

  }

  while(stack.isempty() != 1)
  {
    output[k++] = stack.pop();
  }

  output[k] = '\0';

  cout<<"\nthe output is "<<output<<endl;
}
int main()
{
  char input[50];
  cout<<"enter your input : " << endl;

  cin.getline(input , sizeof(input));

  infixtopostfix(input);

  return 0;
}
