// Devrajsinh Jhala
// Date: 17th Oct. 21
// Arrays -> Collection of variables of same type referred by common name

#include<iostream>
using namespace std;

int main(){

    int pos,num;// pos for position at which arry to be inserted
    // num is the number you want to insert
    int a[100] = {1,2,3,4,5};
    cin >> pos >> num;

    for(int i=4;i>=pos;i--){
        a[i+1] = a[i];
    }
    a[pos] = num;

    for(int i=0;i<6;i++){
        cout << a[i] << " ";
    }

    return 0;
}