#include<iostream>
using namespace std;
int main(){
    int n,key, a,i;
cout<<"size of array: =>";
cin>>n;
int arr[n];
cout<<"enter elements in array";
for (i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"enter position";
cin>>key;
key--;
cout<<"enter number";
cin>>a;

 n++;
for(i=n;i>key;i--){
    arr[i]=arr[i-1];

}
arr[key]=a;
for (i=0;i<n;i++){
    cout<<arr[i];
}
return 0;
}
