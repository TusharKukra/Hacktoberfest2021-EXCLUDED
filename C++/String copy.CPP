#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[10]="Hello";
	char str2[10]="World";
	char str3[10];
	strcpy(str3,str);
	cout<<str3;
	int a=strlen(str3);
	cout<<a<<"\n";
}