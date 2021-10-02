#include <bits/stdc++.h>
using namespace std;

vector<string> jumpStairs(int n)
{
    if (n == 0)
    {
        vector<string> temp;
        temp.push_back("");
        return temp;
    }

    else if (n < 0)
    {
        vector<string> temp;
        return temp;
    }

    vector<string> n1 = jumpStairs(n - 1);
    vector<string> n2 = jumpStairs(n - 2);
    vector<string> n3 = jumpStairs(n - 3);

    vector<string> result;

    for (auto it : n1)
    {
        string t = "1" + it;
        result.push_back(t);
    }

    for (auto it : n2)
    {
        string t = "2" + it;
        result.push_back(t);
    }

    for (auto it : n3)
    {
        string t = "3" + it;
        result.push_back(t);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<string> result = jumpStairs(n);

    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}