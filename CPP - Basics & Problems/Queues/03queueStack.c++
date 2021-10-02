#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

class que{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout << "Queue empty" << '\n';
            return -1;
        }
        if(s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }
    bool empty(){
         if(s1.empty() && s2.empty()){
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

