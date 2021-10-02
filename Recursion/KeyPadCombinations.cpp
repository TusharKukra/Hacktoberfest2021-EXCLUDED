#include <bits/stdc++.h>
using namespace std;

string global[10] = {",:", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> keypadCombination(string s)
{
    if (s.size() == 0)
    {
        vector<string> temp2;
        temp2.push_back("");
        return temp2;
    }

    char c = s[0];
    int number = (int)c - 48;
    string tempStr = s.substr(1, s.size());
    vector<string> temp = keypadCombination(tempStr);

    string str = global[number];
    vector<string> result;

    for (auto it : temp)
    {
        for (int i = 0; i < str.size(); i++)
        {
            string var1 = str[i] + it;
            result.push_back(var1);
        }
    }

    return result;
}

int main()
{
    string str;
    cin >> str;

    vector<string> result = keypadCombination(str);

    cout << endl;
    cout << result.size() << endl;
    for (auto it : result)
    {
        cout << it << endl;
    }
    return 0;
}