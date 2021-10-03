#include<iostream>
using namespace std;
int deleteEle(int arr[],int arraysize,int element)
{
    int i,j;
    for(i=0;i<arraysize;i++)
    {
        if(arr[i]==element)
        {
            break;
        }
    }
    if(i==arraysize)
    {
        return arraysize;
    }
    for(j=i;j<arraysize-1;j++)
    {
        arr[j]=arr[j+1];
    }
    cout<<endl;
    for(i=0;i<arraysize-1;i++)
    {
        cout<<arr[i]<<",";
    }
    return (arraysize-1);
}
int main()
{
    int arraysize=5;
    int arr[arraysize]={3,8,12,5,6};
    int element;
    cout<<"Enter Element you wish to delete:";
    cin>>element;
    cout<<endl;
    for(int i=0;i<arraysize;i++)
    {
        cout<<arr[i]<<",";
    }
    deleteEle(arr,arraysize,element);
    return 0;
}
