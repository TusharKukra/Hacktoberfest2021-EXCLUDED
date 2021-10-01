#include<iostream>
using namespace std;
void heapify(int A[],int n,int i)
{
	int small=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && A[l]<A[small])
	{
		small=l;
	}
	if(r<n && A[r]<A[small])
	{
		small=r;
	}
	if(small!=i)
	{
		int b =A[small];
		A[small]=A[i];
		A[i]=b;
		heapify(A,n,small);
	}
}
void heapsort(int A[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		heapify(A,n,i);
	}
	for(int i=n-1;i>0;i--)
	{
		int b=A[0];
		A[0]=A[i];
		A[i]=b;
		heapify(A,i,0);
	}
}
int main()
{
	int A[]={12, 11, 13, 5, 6, 7};
	int len=sizeof(A)/(sizeof(A[0]));
	heapsort(A,len);
	for(int i=0;i<len;i++)
	{
		cout<<A[i];
	}
}
