// Finding the position of an element in the array using binary search

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, x;
	cin >> n >> x;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int l=0, r=n-1, mid, pos=-1;
	while(l <= r)
	{
		mid = (l + r)/2;
		if(arr[mid]==x)
		{
			pos=mid;
			break;
		}
		else if(arr[mid]<x)
			l = mid +1;
		else
			r = mid - 1;
	}
	cout<<pos+1;

	return 0;
}
