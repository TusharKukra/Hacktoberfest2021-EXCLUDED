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
// detection by floyd's algorithm or hare&turtle algorithm
void detectnDeleteCycle(node* &head){
    node* slow=head;
    node* fast=head;
    bool res=false;
    while(fast != NULL && fast->next != NULL && res==false){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            res = true;
            // break;
        }
    }
    if(res){
        fast = head;
        while(fast->next != slow->next && fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next = NULL;
        // fast = head;
    }
}
void makeCycle(node* &head, int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next != NULL){
        if(count == pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
int main(){
    node* head = NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    insertTail(head,6);
    makeCycle(head,3);
    detectnDeleteCycle(head);
    displayLinkedList(head);
    
    
}