#include<iostream>
using namespace std;


int main()
{
	int n=512;
	
	// this is by bit manipulation
	// we check for power of 2

	if(n && (n & (n-1))==0)
		cout<<"It is Power of 2.";
	else 
		cout<<"It is not.";
}