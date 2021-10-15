#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s = "gajahajkuy";

    int count[26];

    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
    }

    char ans = 'a';
    int maxcount = 0;

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maxcount)
        {
            maxcount = count[i];
            ans = i + 'a';
        }
    }
    cout << maxcount << " " << ans << endl;
    return (0);
}