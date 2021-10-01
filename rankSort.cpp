#include <iostream>
#include<chrono>
using namespace std;

int arr[20],rank_arr[20],final[20],count=0;

int read(int n)
{
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return n;
}

void rankSort(int n)
{
    for(int i=0;i<n;i++)
    {
        rank_arr[i]=0;
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            count++;
            if(arr[j]<=arr[i])
            {
                rank_arr[i]++;
            }
            else
            {
                rank_arr[j]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        final[rank_arr[i]]=arr[i];
    }
}

void display(int n)
{
    cout << "\nElement" << " - "<<"rank_arr"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "     -     "<<rank_arr[i]<<endl;
    }
    cout<<"\nSorted array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<final[i]<<" ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    read(n);
    rankSort(n);
    cout << "After sorting :" << endl;
    display(n);
    return 0;
}