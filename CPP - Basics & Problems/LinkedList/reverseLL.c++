#include<bits/stdc++.h>
using namespace std;
// method - 1 :- iteration
// method - 2 :- recursion 
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next=NULL;
    }
};
void reverseByIteration(node* &head){
    node* prevPtr = NULL;
    node* currentPtr = head;
    node* nextPtr;
    while(currentPtr != NULL){
        nextPtr = currentPtr->next;
        currentPtr->next = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }
    head = prevPtr;
    delete nextPtr;
}
node* reverseByRecursion(node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* newHead = reverseByRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
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
int main (){
    node* head = NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    displayLinkedList(head);
    // reverseByIteration(head);
    head = reverseByRecursion(head);
    displayLinkedList(head);
}
