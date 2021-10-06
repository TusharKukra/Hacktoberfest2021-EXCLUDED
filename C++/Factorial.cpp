#include <stdio.h>

int f(int n) 
{
  if (n==0) 
  {
  	return 1;
  }
  else
  {
  	return (n * f(n-1));
   } 
}

int main() 
{
  int n;
  printf("enter number is for factorial :");
  scanf("%d", &n);
  printf("The factorial of %d : %d\n", n, f(n));
  
}
