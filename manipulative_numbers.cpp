#include <iostream>
#include <algorithm>
using namespace std;

int highbit(int x)
{
    int k = -1;
    while (x != 0)
    {
        x >>= 1;
        k++;
    }
    return k;
}

int main()
{
    int a[100], b[100], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *p = a, *q = b;
    int m = n / 2;
    sort(p, p + n);
    int k = highbit(p[m]);
    while (k >= 0)
    {
        int x = 1 << k;
        for (int i = 0; i < n; i++)
            q[i] = p[i] ^ x;
        sort(q, q + n);
        int s = highbit(q[m]);
        if (s == k) break;
        swap(p, q);
        k = s;
    }
    cout << k << endl;
    return 0;
}
