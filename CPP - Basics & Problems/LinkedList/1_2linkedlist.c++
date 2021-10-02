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
bool search(node* head, int key){
    node* temp=head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}
void deletion(node* head, int val){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
int main (){
    node* head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    // displayLinkedList(head);
    // cout << search(head,3 );
    // deletion(head,3);
    deleteAtHead(head);
    displayLinkedList(head);
}