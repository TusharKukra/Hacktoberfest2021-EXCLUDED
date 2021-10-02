#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next = NULL;
    }
};
void insertHead(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        n->next = n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next=head;
    head=n;
}
void insertTail(node* &head, int val){
    if(head == NULL){
        insertHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next=head;
}
void displayLinkedList(node* head){
    node* temp=head;
    do{
        cout << temp->data <<" --> ";
        temp=temp->next;
    }
    while(temp != head);
    cout << "NULL" << '\n';
}
void deleteHead(node* &head){
    node* temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head=head->next;
    delete todelete;
}
void deletion(node* &head, int pos){
    if(pos==1){
       deleteHead(head);
        return;
    }
    node* temp=head;
    int count = 1;
    while( count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
int main(){
    node* head=NULL;
    int arr[3] = {1,2,3};
    for(int i=0; i<3; i++){
        insertTail(head, arr[i]);
    }
    insertHead(head,4);
    displayLinkedList(head);
    deletion(head,1);
    displayLinkedList(head);
}