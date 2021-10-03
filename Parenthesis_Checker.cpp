/* 
    
    Given an expression string x.
    Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
    For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

    Input:
    {([])}
    Output: 
    true
    Explanation: 
    { ( [ ] ) }. Same colored brackets can form 
    balaced pairs, with 0 number of 
    unbalanced bracket.

*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.

    bool ispar(string x)
    {
        stack<char> st;
        for(int i=0; i<x.length(); i++){
            char ch=x[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else {
                if(ch==')'){
                    if(st.size()==0 || st.top()!='('){
                        return false;
                    }
                    else st.pop();
                }
                else if(ch=='}'){
                    if(st.size()==0 || st.top()!='{'){
                        return false;
                    }
                    else st.pop();
                }
                else if(ch==']'){
                    if(st.size()==0 || st.top()!='['){
                        return false;
                    }
                    else st.pop();
                }
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>a;
   Solution obj;
   if(obj.ispar(a))
    cout<<"balanced"<<endl;
   else
    cout<<"not balanced"<<endl;
}  // } Driver Code Ends