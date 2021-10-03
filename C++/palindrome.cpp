#include <iostream>  
using namespace std;  
int main()  
{  
  int n,r,sum=0,temp;    
  cout<<"Enter the Number To Check Palindrome or Not";    
  cin>>n;    
 temp=n;    
 while(n>0)    
{    
 r=n%10;    
 sum=(sum*10)+r;    
 n=n/10;    
}    
if(temp==sum)    
cout<<temp<<" is Palindrome Number.";    
else    
cout<<temp<<" is not Palindrome Number.";   
  return 0;  
}  
