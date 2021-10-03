#include <iostream>
using namespace std;
union ch 
{
    int d;
    char c;
};
struct un {
    int tag;
    union ch t;
};
struct stack {
    int size=30;
    int top=-1;
    struct un elem[30];
};
struct stack1 {
    int size=30;
    int top=-1;
    int elem[30];
};
void push(stack1 &s,int x) {
    if (s.top<s.size-1) s.elem[++s.top]=x;
}
int pop(stack1 &s) {
    if (s.top>-1) return s.elem[s.top--];
}
void dsa(stack1 &s,char c) {
    int t1,t2;
    if (c=='+') { 
        t1=pop(s);  t2=pop(s);  push(s,t1+t2); 
    }
    if (c=='-') { 
        t1=pop(s);  t2=pop(s);  push(s,t1-t2);
    }
    if (c=='*') { 
        t1=pop(s);  t2=pop(s);  push(s,t1*t2);
    }
    if (c=='/') { 
        t1=pop(s);  t2=pop(s);  push(s,t1/t2);
    }
}
int main() {
    stack s;
    stack1 s1;
    int t1,t=0;
    while (t1!=-1) {
        cin>>t1;
        if (t1!=-1) {
            t++;
            s.top++;
            s.elem[s.top].tag=t1;
            if (t1==1) cin>>s.elem[s.top].t.c;
            else cin>>s.elem[s.top].t.d;
        }
    }
    for (int i=0;i<t;i++) {
        if (s.elem[s.top].tag==0) { push(s1,s.elem[s.top].t.d); s.top--; }
        else {dsa(s1,s.elem[s.top].t.c); s.top--; }
    }
    cout<<s1.elem[s1.top];
}
