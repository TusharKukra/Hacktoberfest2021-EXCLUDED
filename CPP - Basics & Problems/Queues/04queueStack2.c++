#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

class que{
    stack<int> s1;
    // stack<int> s2;
public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout << "Queue empty" << '\n';
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;
    }
    bool empty(){
         if(s1.empty()){
            return 1;
        }
        return 0;
    }

};
int main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    for(int i=0; i<5; i++){
        cout << q.pop() << " ";
    }
    cout << '\n';
    cout << q.empty() << '\n';
    cout << q.pop();
}

