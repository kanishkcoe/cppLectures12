#include <iostream>

using namespace std;

void multiply(int a[10][10], int b[10][10], int c[10][10], int m, int n, int p, int q, int row, int col)
{
  if(n != p)
  {
    return;
  }

  row = m;
  col = q;
  int sum;

  for(int x = 0; x < m; x++)
  {
    for(int y = 0; y < q; y++)
    {
      sum = 0;

      for(int j = 0, i = 0; j < n && i < p; j++, i++)
      {
        sum += a[x][j] + b[i][y];
      }

      c[x][y] = sum;
    }
  }

}

int main()
{


  return 0;
}
