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
int length(node* head){
    int l=0;
    node* temp=head;
    while(temp != NULL){
        temp=temp->next;
        l++;
    }
    return l;
}
node* appendKnode(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int lengthOfLL = length(head);
    k = k % lengthOfLL;
    int count=1;
    while(tail->next != NULL){
        if(count == lengthOfLL-k){
            newTail = tail;
        }
        if(count == lengthOfLL-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}
int main (){
    node* head=NULL;
    // Method 1 to make a LL
    // insertTail(head,1);
    // insertTail(head,2);
    // insertTail(head,3);
    // insertTail(head,4);
    // insertTail(head,5);
    // insertTail(head,6);
    // insertTail(head,7);

    // method - 2 to make a LL
    int arr[6] = {1,2,3,4,5,6};
    for(int i=0; i<6; i++){
        insertTail(head, arr[i]);
    }
    displayLinkedList(head);
    node* newhead = appendKnode(head,3);
    displayLinkedList(newhead);
}