#include <stdio.h>
int main() 
{
    int arr[50] ;
    int n ;
    int i , j= 0 ;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the elements : \n");
    for(i = 0; i<n; i++)
    {    
        scanf(" %d " , &arr[i]);
    }
    for(int i = 0;i <n+1; i++)
    {
        printf("the elements of array are : ");
        printf("%d \n ", arr[i]);
    }
}