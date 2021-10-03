/* 
    You are given an array arr[] of size n.
    Find the total count of sub-arrays having their sum equal to 0.

    Input:
    n = 6
    arr[] = {0,0,5,5,0,0}
    Output: 6
    Explanation: The 6 subarrays are 
    [0], [0], [0], [0], [0,0], and [0,0].

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> a, int n ) {
        //code here
        map<ll,ll> m;
        
        ll sum=0,ans=0;
        m[sum]=1;
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(m[sum]>0){
                ans+=m[sum];
            }
            m[sum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{

    int n;
    cin>>n; //input size of array
   
    vector<ll> arr(n,0);
    
    for(int i=0;i<n;i++)
        cin>>arr[i]; //input array elements
    Solution ob;
    cout << ob.findSubarray(arr,n) << "\n";
        
    return 0;
}  // } Driver Code Ends