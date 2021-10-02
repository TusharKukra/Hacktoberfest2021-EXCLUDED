#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[100];
	char str2[100];
	cout<<"Enter two string: "<<"\n";
	cin>>str>>str2;
	int z=strcmp(str,str2);
	cout<<z<<"\n";
}