/* 6.3 Sort Algorithm- Insertion Sort */

/*
InsertionSort- imaginary hole, compare hole-1 element with hole value,insert if less
*/


/*  Insertion sort  */

#include <iostream>
using namespace std;

void InsertionSort(int A[], int n)
{
	int i,j;
	for(i = 0; i < n; i++){
		int temp = A[i];
		for(j = i - 1; j >= 0 && A[j] > temp; j--){
			A[j + 1] = A[j];
		}
		A[j + 1] = temp;
	}
}

int main()
{
    int num;
    cout<<"How many elements: ";
    cin>>num;
    int *A=new int[num];
    cout<<"Enter the numbers: \n";
    for(int i=0;i<num;i++){
        cin>>A[i];
    }
    cout<<"Sorted list: ";
    InsertionSort(A,num);
    for(int i=0;i<num;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}



