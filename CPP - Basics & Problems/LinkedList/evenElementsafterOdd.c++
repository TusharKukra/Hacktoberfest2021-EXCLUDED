#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
typedef node *LPTR;
void addback(LPTR L,int x) {
    while (L!=NULL) L=L->next;
    L=new(node);
    L->data=x;
    L->next=NULL;
}
int create(LPTR &L) {
    int n,t=0;cin>>n; if (n%2 && n!=-1) t++;
    L->data=n;
    L->next=NULL;
    while (n!=-1) {
        cin>>n; if (n%2 && n!=-1) t++;
        if (n!=-1) addback(L,n);
    } return t;
}
void printf(LPTR L) {
    while (L->next!=NULL) { cout<<L->data<<" "; L=L->next; }
    cout<<L->data<<endl;
    return;
}
LPTR segregate(LPTR &L,int t) {
    int i=0;
    LPTR L1=L;
    while (i<t) {
        if (L->data%2==0) {
            i++;
            addback(L,L->data);
            L=L->next;L1=L;
        }
        else if (L1->next->data%2==0) {
            i++; 
            addback(L1,L1->next->data);
            L1->next=L1->next->next;
        } else L1=L1->next;
    }
    return L;
}
int main() {
    LPTR L1;
    L1=new(node);
    int t=create(L1);
    printf(L1);
    L1=segregate(L1,t);
    printf(L1);
}
