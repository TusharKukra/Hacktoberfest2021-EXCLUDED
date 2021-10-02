#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t, n, maxm = 100000001, row=1, col=1;
	map <int, pair<int,int>> mp;
	vector <bool> notPrime(maxm);
	notPrime[0] = 1;
	notPrime[1] = 1;
	cin >> t;

	for(int i=2; i*i < maxm; i++)
	{
		if(notPrime[i] == 0)
		{
			mp[i] = make_pair(row, col);
			col++;
			if(col>row)
			{
				row++;
				col=1;
			}
			for(int j=i*i; j < maxm; j+=i)
			{
				notPrime[j] = 1;
			}
		}
	}

	while(t--)
	{
		cin >> n;
		if(notPrime[n] == 1)
			cout << -1;
		else
			cout << mp[n].first << " " << mp[n].second;

		cout << endl;
	}

	return 0;
}
