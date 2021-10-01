#include <iostream>
using namespace std;

int arr[200],c=0;

int read(int n)
{
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return n;
}

void insertionSort(int n)
{
    int j,key;
    for (int i = 1; i < n ; i++)
    {
        j = i - 1;
        key=arr[i];
        while (j >= 0 && arr[j] > key)
        {
             c++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements : " << endl;
    cin >> n;
    read(n);
    insertionSort(n);
    cout << "After sorting :" << endl;
    display(n);
    return 0;
}