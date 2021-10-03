#include<iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int arr[]={50,8,20,100};
    cout<<isSorted(arr,4);
    return 0;
}
