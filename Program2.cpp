#include <iostream>
using namespace std;

 
int sortRowWise( int M, int N, int** a)
{

  for (int i = 0; i < M; i++)
    sort(a[i], a[i] + N);
 
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
      cout << (a[i][j]) << " ";
    cout << endl;
  }
  return 0;
}
 
// Driver code
int main()
{
  int m,n;
  cin>>m>>n;
  int** a = new int[m][n];
  sortRowWise(m,n,a);
}
