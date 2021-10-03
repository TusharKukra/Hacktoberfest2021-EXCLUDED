/*
1
1 2
1   3
1     4
1 2 3 4 5
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "\n1 "<<endl;;
    for(int i=2;i<n;i++){
        cout << "1 ";
        for(int j=i-2;j>0;j--){
            cout << "  ";
        }
        cout << i << " " << endl;
    }
    for(int i=1;i<=n;i++) cout << i << " ";
    cout<<endl;
}