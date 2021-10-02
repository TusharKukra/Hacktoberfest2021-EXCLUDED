/*******************************
 A. Lucky Division
time limit per test2 seconds
memory limit per test256 megabytes

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya calls a number almost lucky if it could be evenly divided by some lucky number. Help him find out if the given number n is almost lucky.

Input
The single line contains an integer n (1 ≤ n ≤ 1000) — the number that needs to be checked.

Output
In the only line print "YES" (without the quotes), if number n is almost lucky. Otherwise, print "NO" (without the quotes).

Examples
Sample input
47
Sample output
YES
 *************************/

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair

#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) ((v).begin()), ((v).end())
#define allr(w) ((w).rbegin()), ((w).rend())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

/*********************************/

bool isPowOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

bool cmp1(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

ll min3(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

ll min4(ll a, ll b, ll c, ll d)
{
    return min(a, min(b, min(b, c)));
}

ll max3(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}

ll max4(ll a, ll b, ll c, ll d)
{
    return max(a, max(b, max(b, c)));
}

/*********************************/

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi v = {4, 7, 47, 74, 477, 447, 474, 774, 747};
    for (int i = 0; i < v.size(); i++)
    {
        if (n % v[i] == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}