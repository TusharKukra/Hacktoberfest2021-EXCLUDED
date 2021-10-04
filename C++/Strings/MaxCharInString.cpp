#include <bits/stdc++.h>
using namespace std;

/*
PROBLEM STATEMENT:
Given a string, find the character that appears mostly.
If there is a tie, return the lexicographically smallest character.

Sample Test Case:
Input: "aabbaccd"
Output: "a" -> appereances: a: 3 times > b: 2 times >= c: 2 time > d: 1 times

Input: "Hacktoberfest"
Output: "e" -> appears 2 times >= t: 2 times and all other characters appear 1 time

Input: "abcdefghijklmnopqrstuvwxyz"
Output: "a" -> no majority character in the string -> return the lexicographically smallest character

*/ 

// Using Map to store the character and its frequency
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(n) where we using extra space to store the map
string maxChar(string s)
{
    vector<char>vec;
    for(int i=0;i<s.size();i++)
    {
        vec.push_back(s[i]);
    }
    map<char,int>dummy;
    for(auto &it:vec)
    {
        auto res=dummy.insert(pair<char,int>(it,1));
        if(res.second==false)
            res.first->second++;
    }
    int max=0;
    string c;
    for(auto &it:dummy)
    {
        if(it.second>max)
        {
            max=it.second;
            c=it.first;
        }
    }
    return c;
}

int main()
{
    string str;
    cin>>str;
    string ans=maxChar(str);
    cout<<ans;
    return 0;
}
//------------------------------------------------------//

//Hashing Technique without using map stl library
//TC: O(n) SC: O(n)
#include <bits/stdc++.h>
using namespace std;

string maxChar(string s)
{
    int a[256]={0};
    int max=0;
    string st;
    for(int i=0;i<s.size();i++)
    {
        a[s[i]]++;
        if(a[s[i]]>max)
        {
            max=a[s[i]];
            st=s[i];
        }
    }
    return st;
}

int main()
{
    string s;
    cin>>s;
    string res=maxChar(s);
    cout<<res;
    return 0;
}

//-----------Thank You So Much----------------//
//-----------Hope this helped you------------//