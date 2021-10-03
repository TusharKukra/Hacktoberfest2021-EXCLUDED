#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int mid,int left,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1],rightArr[n2];
  
    for(int i=0;i<n1;i++){
        leftArr[i]=arr[left+i];
    }

    for(int i=0;i<n2;i++){
        rightArr[i]=arr[mid+i+1];
    }

    int i{},j{},k = left;
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        }else {
            arr[k++]=rightArr[j++];
        }
    }

    while(i<n1)
        arr[k++]=leftArr[i++];

    while(j<n2)
        arr[k++]=rightArr[j++];    
}

void mergeSort(int arr[],int left,int right){
    if(left>=right)
        return;

  int mid = left + (right-left)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,mid,left,right);    
} 

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}