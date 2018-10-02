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

      temp->next = NULL;
      temp->data = x;

      if(top == NULL)
      {
        top = temp;
        return;
      }

      temp->next = top;
      top = temp;
    }

    char pop()
    {
      char x = top->data;

      Node *temp;
      temp = top;

      top = top->next;
      delete temp;

      return x;
    }

    int isEmpty()
    {
      if(top == NULL)
        return 1;

      return 0;
    }

    char peak()
    {
      char x = top->data;

      return x;
    }
};


int precedence(char symbol)
{
  switch (symbol)
  {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
  }
}

void changeToPostFix(char * input)
{
  Stack stack;

  char output[50];
  int k = 0;

  for(int i = 0; input[i] != NULL; i++)
  {
    char scannedSymbol = input[i];

    if(isalpha(scannedSymbol))
    {
      output[k++] = scannedSymbol;
      continue;
    }
    else if(stack.isEmpty() == 1)
    {
      stack.push(scannedSymbol);
      continue;
    }
    else if(scannedSymbol == '(')
    {
      stack.push(scannedSymbol);
      continue;
    }
    else if(scannedSymbol == ')')
    {
      while(stack.peak() != '(')
      {
        char poppedSymbol = stack.pop();
        output[k++] = poppedSymbol;
      }
      stack.pop();
    }
    else if(precedence(scannedSymbol) > precedence(stack.peak()))
    {
      stack.push(scannedSymbol);
      continue;
    }
    else if(precedence(scannedSymbol) <= precedence(stack.peak()))
    {
      while(stack.isEmpty() != 1 && precedence(scannedSymbol) <= precedence(stack.peak()))
      {
        char poppedSymbol = stack.pop();
        output[k++] = poppedSymbol;
      }
      stack.push(scannedSymbol);
      continue;
    }
  }

  while(stack.isEmpty() != 1)
  {
    char poppedSymbol = stack.pop();
    output[k++] = poppedSymbol;
  }
  cout << output << endl;
}

int main()
{
  char input[50];

  cout << "Enter infix string : " << endl;
  cin >> input;


  cout << "Postfix string : " << endl;
  changeToPostFix(input);

  return 0;
}
