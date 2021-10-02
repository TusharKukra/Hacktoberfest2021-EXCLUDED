#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }else if(!st.empty() && s[i] == ')' && st.top() == '('){
            st.pop();
        }else if(!st.empty() && s[i] == '}' && st.top() == '{'){
            st.pop();
        }else if(!st.empty() && s[i] == ']' && st.top() == '['){
            st.pop();
        }else{
            return false;
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

int main(){
    string s = "({[]})]";
    if(isBalanced(s)){
        cout << "Balanced!" << '\n';
    }else{
        cout << "Unbalanced" << '\n';
    }
}
