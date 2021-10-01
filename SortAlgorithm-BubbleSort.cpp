/* 6.2-b Sort Algorithm- Bubble Sort */

/*alternate method*/

#include<iostream>
using namespace std;

void bubbleSort(int A[], int n)
{
    for(int i = 0; i < n-1; i ++)
    {
        for(int j = n-1; j > i; j--) // Attention: reverse loop 
        {
            if(A[j-1] > A[j])
            {
                // Swap elements if the lower-indexed key's value is greater
                // than its higher-indexed neighbor
                int temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
            }
        }
    }
}


int main()
{
    int num;
    cout<<"How many elements: ";
    cin>>num;
    int *A=new int;
    cout<<"Enter the numbers: \n";
    for(int i=0;i<num;i++){
        cin>>A[i];
    }
    //int A[]={2,7,4,1,5,3};
    cout<<"Sorted list: ";
    bubbleSort(A,num);
    for(int i=0;i<num;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}

