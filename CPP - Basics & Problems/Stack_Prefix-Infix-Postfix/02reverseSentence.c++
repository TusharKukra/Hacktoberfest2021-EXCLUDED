#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        string word="";
        while(s[i] != ' ' && i<s.size()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!s.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

int main(){
    string s = "Hey, How are you doing?";
    reverseSentence(s);
}
