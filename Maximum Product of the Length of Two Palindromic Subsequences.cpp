// Q.Given a string s, find two disjoint palindromic subsequences of s such that the product
// of their lengths is maximized. The two subsequences are disjoint if they do not both pick 
// a character at the same index. Return the maximum possible product of the lengths of the 
// two palindromic subsequences.

// My approach

// By seeing the constraints, it can be inferred that brute force approach should work fine.
// To make disjoint subsequence we'll use 2 strings . Now, at everry character i in string 
// we have 3 choices:

// 1)include that char in first string
// 2)include that char in second string
// 3)exclude that char from both strings

// to achieve this we'll use backtracking to generate all disjoint subsequences.
// Now of these subsequences , we consider only those which are pallindromic and leave the rest.
// For the pallindromic subsequence pair we calculate product eachtime and comapre with our ans 
// calculated so far and update it if the latter product is greater.

//My code

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long long ans = 0;
    
    bool isPal(string &s)
    {
        int start=0, end = s.length()-1;
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++; end--;
        }
        return true;
    }
    
    void recur(string &s,int idx,string &s1,string &s2)
    {
        if(idx == s.size())
        {
            if(isPal(s1) and isPal(s2))
            {
                long long val =(int) s1.length() * s2.length();
                ans = max(ans , val);
            }
            return;
        }
        
        s1.push_back(s[idx]);
        recur(s,idx+1,s1, s2);
        s1.pop_back();
        
        s2.push_back(s[idx]);
        recur(s,idx+1,s1,s2);
        s2.pop_back();
        
        recur(s,idx+1,s1,s2);
    }
	
	int maxProduct(string s) {
        string s1="", s2 = "";
        recur(s,0,s1,s2);
        return ans;
    }
  int main(){
    string s;
    cin>>s;
    cout<<maxProduct(s);
  }  
