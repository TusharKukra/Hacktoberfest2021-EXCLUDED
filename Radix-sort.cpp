#include<iostream> 
#include<bits/stdc++.h>
using namespace std; 

int getMax(int arr[], int size) 
{ 
    int max = arr[0]; 
    for (int i = 1; i < size; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
    return max; 
} 
  
void CountingSort(int arr[], int size, int div) 
{ 
    int output[size]; 
    int count[10] = {0}; 
  
    for (int i = 0; i < size; i++) 
        count[ (arr[i]/div)%10 ]++; 
  
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = size - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/div)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/div)%10 ]--; 
    } 
  
    for (int i = 0; i < size; i++) 
        arr[i] = output[i]; 
} 
  
 
void RadixSort(int arr[], int size) 
{ 
    int m = getMax(arr, size); 
    for (int div = 1; m/div > 0; div *= 10) 
        CountingSort(arr, size, div); 
} 
  

int main() 
{ 
	int size=6;
	int arr[6]={3,2,1,4,5,3};
	
	RadixSort(arr, size); 
   
	
   for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	} 
    
    return 0; 
}