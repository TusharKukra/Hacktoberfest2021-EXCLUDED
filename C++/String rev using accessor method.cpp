#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char arr[50];
	char arr1[50];
	cout<<"Enter a String: \n";
	cin>>arr;
    arr1[50] = arr[50];
	cout<<"String before rev.\n";
	cout<<arr;
	cout<<"\nString after rev.\n";
	strrev(arr);
	cout<<arr;
	cout<<"\n";
	
}
