#include <bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] << " -- "
			<< next << endl;
	}
}

int main()
{
	int arr[] = {27, 18, 11, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}

