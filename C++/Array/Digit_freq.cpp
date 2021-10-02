#include<bits/stdc++.h>
using namespace std;

int getMaxfre(int arr[],int n, int d) {

    int count = 0;
    for (int p=0; p< n; p++){
       if (arr[p] == d){
          count++;
           
       }
    }
          return count;
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int p=0;p<n;p++){
        cin>>arr[p];
    }
    int d;
    cin>>d;

    cout<<getMaxfre(arr,n,d)<<endl;

    return 0;
}




