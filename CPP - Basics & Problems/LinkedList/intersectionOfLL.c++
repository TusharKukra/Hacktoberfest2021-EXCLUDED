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
void intersect(node* &head1, node* &head2, int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next != NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l1;
        ptr1= head1;
        ptr2 = head2;
    }else{
        d = l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }
    while( ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
int main(){
    node* head1=NULL;
    node* head2=NULL;
    int arr[6] = {1,2,3,4,5,6};
    int arr2[2] = {9,10};
    for(int i=0; i<6; i++){
        insertTail(head1, arr[i]);
    }
    for(int i=0; i<2; i++){
        insertTail(head2,arr2[i]);
    }
    // displayLinkedList(head);
    intersect(head1, head2,3);
   cout << intersection(head1, head2);
}