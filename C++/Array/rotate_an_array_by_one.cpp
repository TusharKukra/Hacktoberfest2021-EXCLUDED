/*
Problem Description: Cyclically rotate an array by one.
Time Complexity: O(N)

Sample Input:
1
6
4 10 2 3 20 9

Sample Output:
9 4 10 2 3 20 

*/

#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int temp=arr[n-1];
    for(int i=n-1; i>=1; --i){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n] , i;
        for(i=0;i<n;i++)
            cin >> a[i];
        rotate(a, n);
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
        return 0;
}


