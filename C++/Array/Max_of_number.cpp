#include<iostream>
using namespace std;
int main(){
    int mx=-1999999;
    int n;
    cin>>n;

    int arr[n];
    for(int k=0;k<n;k++){
       cin>>arr[k];
    }

    for(int k=0;k<n;k++){
        mx=max(mx,arr[k]);
        cout<<mx<<endl;
    }
    return 0;
}