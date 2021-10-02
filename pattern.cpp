/*
Aim: To print the following pattern:
    0 0 0 0 0 0 0 0 0
    0 1 1 1 1 1 1 1 0
    0 1 2 2 2 2 2 1 0
    0 1 2 3 3 3 2 1 0
    0 1 2 3 4 3 2 1 0
    0 1 2 3 3 3 2 1 0
    0 1 2 2 2 2 2 1 0
    0 1 1 1 1 1 1 1 0
    0 0 0 0 0 0 0 0 0
*/

#include <iostream>
using namespace std;

void pattern(int n){
    n = (2 * n);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            int element = min(min(i, j), min(n - i, n - j));
            cout << element << " ";
        }
        cout << endl;
    }
}

int main(){

    int n;
    cin >> n;

    pattern(n);

    return 0;
}