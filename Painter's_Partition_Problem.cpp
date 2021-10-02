/* 
Dilpreet wants to paint his dog's home that has n boards with different lengths. 
The length of ith board is given by arr[i] where arr[] is an array of n integers.
He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the
constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

*********INPUT************
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35

*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isvalid(int a[], int n, int k, long long mid){
        int p=1;
        long long sum=0;
        for(int i=0; i<n; i++){
            if(a[i]>mid) return false;
            sum+=a[i];
            if(sum>mid){
                p++;
                sum=a[i];
            }
            if(p>k) return false;
        }
        return true;
    }
    long long minTime(int a[], int n, int k)
    {
        
        long long res=-1;
        long long sum=0;
        int mx=0;
        for(int i=0;i<n; i++){
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        long long start=mx, end=sum;
        while(start<=end){
            long long mid= start + (end-start)/2;
            if(isvalid(a,n,k,mid)){
                res=mid;
                end=mid-1;
            }
            else start = mid+1;
        }
            return res;
    }
};

// { Driver Code Starts.

int main()
{
    
    int k,n;
    cin>>k>>n;
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;

    return 0;
}  // } Driver Code Ends