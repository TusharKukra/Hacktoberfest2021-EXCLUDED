#include<iostream>
using namespace std;


long long int decToBin(int n){
	
	if(n == 0){
		return 0;
	}
	
	
	return (n%2+10 * decToBin(n/2));
	
	
}

int main(){

	int n;
	
	cout<<"Enter the number"<<endl;
	
	cin>>n;
	
	long long int ans=decToBin(n);
	
	cout<<"Ans is "<<ans<<endl;
	
	
	return 0;
}
