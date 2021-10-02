#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}
void insertTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){ 
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void displayLinkedList(node* head){
    node* temp=head;
    while(temp != NULL){
        cout << temp->data<<" --> ";
        temp=temp->next;
    }
    cout << "NULL" << '\n';
}
node* reverseK(node* &head, int k){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    int count=0;
    while(currPtr != NULL && count<k){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr=currPtr;
        currPtr=nextPtr;
        count++;
    }
    if(nextPtr != NULL){
    head->next=reverseK(nextPtr, k);
    }
    return prevPtr;
}
int main(){
    node* head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertTail(head,6);
    displayLinkedList(head);
    head = 
    reverseK(head, 2);
    displayLinkedList(head);
}