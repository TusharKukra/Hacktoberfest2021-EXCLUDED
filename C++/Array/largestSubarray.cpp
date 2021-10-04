/**
 * Given an array of 0s and 1s. 
 * Find the length of the largest subarray with equal number of 0s and 1s.
 * /
 * */
#include <bits/stdc++.h>
using namespace std;
int maxLen(int ar[], int n)
{
   unordered_map<int,int>mp;
   int i,j,mx=0;
   i=0;
   int s=0;
   for(i=0;i<n;i++)
   {
       if(ar[i]==0)
       s+=-1;
       else
       s+=1;
       if(s==0)
       {
           mx=max(mx,i+1);
       }
       if(mp.find(s)!=mp.end())
       {
           mx=max(mx,i-mp[s]);
       }
       else
       mp[s]=i;
   }
   return mx;
}


int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin >> n;
    cout<<"Enter "<<n<<" elements\n";
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxLen(a, n) << endl;
    return 0;
} 