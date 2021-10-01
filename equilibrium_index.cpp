#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int equilibrium_point(vector<int> arr, int n)
{
    int sum = 0, sum1=0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    for(int i = 0; i<n; i++)
    {
        sum = sum - arr[i];
        cout<<"Updated total Sum is : "<<sum<<endl;
        if(sum1 == sum)
        {
            return i+1;
        }
        sum1 = sum1+arr[i];
        cout<<"Equilibrium Sum is: "<<sum1<<endl;
    }
     return -1;
}


int main()
{
    vector<int> arr;
    int size=0, input;
    cout<<"Enter array size: ";
    cin>>size;
    cout<<"enter array: "<<endl;
    for (int i =0; i<size; i++)
    {
        cin>>input;
        arr.push_back(input);
    } 
    int point = equilibrium_point(arr, size);
    cout<<"point is: "<<point<<endl;
}