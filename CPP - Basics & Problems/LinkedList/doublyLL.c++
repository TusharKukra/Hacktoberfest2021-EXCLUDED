#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void insertHead(node* &head, int val){
    
    node* n = new node(val);
    // node* head = head;
    // head = n;
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    
    n->prev=NULL;
    head = n;
}
void insertTail(node* &head, int val){
    if(head==NULL){
        insertHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next=NULL;
}

void displayLinkedList(node* head){
    node* temp=head;
    while(temp != NULL){
        cout << temp->data<<" --> ";
        temp=temp->next;
    }
    cout << "NULL" << '\n';
}
void deleteNodeHead(node* &head){
    node* n = head;
    head = head->next;
    head->prev = NULL;
    delete n;
}
// when value of the node is given
void deleteNodeVal(node* &head, int val){
    if(head->data == val){
        deleteNodeHead(head);
        return;
    }
    node* temp = head;
    while(temp->data != val){
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL){
       temp->next->prev = temp->prev;
    }
   
    delete temp;
}
void deleteNodePos(node* &head, int pos){
    if(pos==1){
        deleteNodeHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(temp!= NULL && count != pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
int main(){
    node* head=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    displayLinkedList(head);
    insertHead(head,4);
    displayLinkedList(head);
    // deleteNodeVal(head,4);
    deleteNodePos(head,1);
    displayLinkedList(head);
}