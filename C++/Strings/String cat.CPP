#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[10]="Hello";
	char str2[10]="World";
	char str3[10];
	int len;
	strcat(str,str2);
	cout<<str<<"\n";
	//cout<<str<<" "<<str2<<"\n";
    //str3=str+'\0'+str2;
    //cout<<str3<<"\n";
    //len=str3.size();
    //cout<<"String length: "<<len;
}
