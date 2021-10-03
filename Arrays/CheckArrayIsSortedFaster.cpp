#include<iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i]<arr[i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int arr[]={5,8,20,100};
    cout<<isSorted(arr,4);
    return 0;
}
