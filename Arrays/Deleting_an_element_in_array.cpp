// Devrajsinh Jhala
// Date: 17th Oct. 21

#include<iostream>
using namespace std;

int main()
{
    int a[100] = {1,2,3,4,5};
    int pos; // pos for position at which arry to be inserted
    cin >> pos;

    for(int i=pos;i<5;i++){
        a[i] = a[i+1];
    }

    for(int i=0;i<4;i++){
        cout << a[i] << " ";
    }

    return 0;
}