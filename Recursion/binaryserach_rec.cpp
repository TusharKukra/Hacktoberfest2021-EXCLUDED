#include<iostream>
using namespace std;

int recursiveSearch(int a[],int l,int r,int x){
  
  int mid=(l+r)/2;
  
  if(l==r){
    if(a[l]==x)
       return l;
    else
      return -1;
  } 

				
  if(a[mid]==x)
    return mid;

  if(a[mid]<x)
    return recursiveSearch(a,mid+1,r,x);

  if(a[mid]>x)
    return recursiveSearch(a,l,mid-1,x);

  return -1;
     
}

int main(){
 system("clear");

 int n;
 cout<<"Enter the number of elements of the array\n";
 cin>>n;
 int a[n];

 cout<<"Enter the elements of the array\n";
 for(int i=0;i<n;i++)
  cin>>a[i];
 
 int x;
 cout<<"Enter the element to be searched\n";
 cin>>x;
 
 int index=recursiveSearch(a,0,n-1,x);
  if(index==-1)
    cout<<"Entered element is not present\n";
  else
   cout<<"Entered element is present at index "<<index<<"\n";
   
  return 0;
}  
