#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mid, high, low, number, elementToBeSearch, position = 0;
    bool flag = false;
    cout << "Enter the number of elements in the array:- ";
    cin >> number;
    int array[number];
    for (int i = 0; i < number; i++)
    {
        cout<< "Enter the element "<<i+1<<" in the array ";
        cin>>array[i];
    }
    int n = sizeof(array) / sizeof(array[0]);
    sort(array, array + n);
    for (int i = 0; i < number; i++)
    {
        cout << array[i] << " ";
    }
    cout<<endl;

    // cout<<"Enter the Element you want to search:-";
    // cin>> elementToBeSearch;
    low = 0;
    high = number;
    cout << "Enter the Element to be searched:-";
    cin >> elementToBeSearch;
    while (low <= high)
    {

        mid = (high + low) / 2;
        if (elementToBeSearch < array[mid])
        {
            high = mid - 1;
        }
        else if (elementToBeSearch > array[mid])
        {
            low = mid + 1;
        }
        else if (elementToBeSearch == array[mid])
        {
            flag = true;
            position = mid;
            break;
        }
    }
    if (flag)
    {
        cout << "Position of the element is:- " << position<<endl;
    }else{
        cout<<"Element Not Found";
    }
}
