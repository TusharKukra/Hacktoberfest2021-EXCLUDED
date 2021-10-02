#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topele);
}

void reverseStack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}

int main(){
    stack<int> st;
    for(int i=1; i<=5; i++){
        st.push(i);
    }
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
