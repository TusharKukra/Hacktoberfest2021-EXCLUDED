#include <iostream>
using namespace std;
int c=0;

int *read(int *arr,int n)
{
  cout<<"Enter the elements\n";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  return arr;
}

void display(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int *a, int l, int h)
{
    c++;
    int pivot = a[l], i = l, j = h + 1;
    while (i <= j)
    {
        do
        {
            i++;
        } while (a[i] <= pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j]);
    return j;
}
void quickSort(int *a, int l, int h)
{
    c++;
    if (l < h)
    {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
    else
        return;
}

int main() {
  int n;
  cout<<"Enter the number of elements"<<endl;
  cin>>n;
  int *arr;
  arr=read(arr,n);
  cout << "Unsorted arr: \n";
  display(arr, n);
  quickSort(arr, 0, n - 1);
  cout << "Sorted array: \n";
  display(arr, n);
  return 0;
}