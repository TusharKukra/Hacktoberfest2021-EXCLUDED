#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sol(vector<int>&A){
   int n=A.size(),p1,p2,p3,high=n-1;
   sort(A.begin(),A.end());
   vector<int>ptr,check;
   vector<vector<int>>sol;
   for(int i=0;i<n-2;i++){
     p1=A[i];
     for(int a=i;a<n-1;a++){
         p2=A[a],p3=A[high];
         if(p1+p2+p3==0){
             ptr={p1,p2,p3};
             sol.push_back(ptr);
             ptr.clear();
         }
         else if(p1+p2+p3<0)a++;
         else  high--;
     }
     high=n-1;
   }
  
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    sol(arr);
}