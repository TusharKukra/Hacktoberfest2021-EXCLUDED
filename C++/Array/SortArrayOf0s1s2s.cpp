#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int *a, int n)
    {
        int temp;
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                temp;
                temp = a[low];
                a[low] = a[mid];
                a[mid] = temp;
                low++;
                mid++;
                continue;
            }

            else if (a[mid] == 1)
            {
                mid++;
                continue;
            }

            else
            {
                temp;
                temp = a[mid];
                a[mid] = a[high];
                a[high] = temp;
                high--;
                continue;
            }
        }
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
