

/*
Suppose we have 2 sorted Linked List : 
    1 --> 4 --> 6 -->8

    2 --> 3 --> 5 --> 7 --> 9

We have to merge them to get: 

1 --> 2 --> 3 --> 4 --> 5 --> 6 --> 7 --> 8 --> 9

(New list creation is not Allowed)
*/


class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }

};

void insertAtEnd(node* &head, int d){
    node* n = new node(d);

    if(head==NULL){
        head = n;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}

void printLL(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int length (node* head){
    int count = 0;
    node* temp = head;

    while(temp!=NULL){
        temp = temp->next;
        count++;
    }

    return count;
}


node* mergingTwoLL(node* head1, node* head2){
    //Base Cases: 
    if(head1==NULL){
        // if 1st LL is empty
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    // Recursive Cases :
    node* newHead;
    // new head will point to the smaller head
    // now compare heads of both LL
    if(head1->data < head2->data){
        newHead = head1;

        node* chotaHead =  mergingTwoLL(head1->next , head2);  // recursion
        newHead->next = chotaHead;
    }
    else{
        newHead = head2;
        node* chotaHead = mergingTwoLL(head1, head2->next); // recursion
        newHead->next = chotaHead;
    }

    return newHead;
}

node* mid(node* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	node* slow = head;
	node* fast = head -> next;
	while (fast != NULL and fast -> next != NULL) {
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}

//////////////////////////////////////////////////////////////////

int intersection (node* &head1, node* &head2){
    // firstly find the length of both LL

    int l1 = length(head1);
    int l2 = length(head2);

    // now if the length of the Linked Lists are diff then we will start from the differnce of both Lengths in bigger LL

    // difference of both length of LL : 
    int d =0;  // for calculating difference

    node* ptr1;  // points to the larger length LL
    node* ptr2;  // points to the shorter length LL

    if(l1>l2){  // if 1st LL is larger then ptr1 points to the head1 (1st LL)
        d = l1 -l2;
        ptr1 = head1;
        ptr2 = head2;
    }

    else{  // if 2nd LL is larger then ptr1 points to the head2 (2nd LL)
        d = l2 -l1;
        ptr1 = head2;
        ptr2 = head1;
    }


    // now check the value of d (till it reaches 0)
    while(d){

        ptr1 = ptr1->next;  // move pointer 1
        // move till it becomes null
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        
    }
    return -1;

}

//////////////////////////////////////////////////////////////////

int main(){
    node* head1, *head2;
    head1 = head2 = NULL;

    int n,m;
    cin>>n;
    cin>>m;

    for(int i=0;i<n;i++){
        int data;
        cin>>data;

        insertAtEnd(head1,data);
    }

    for(int j=0;j<m;j++){
        int data;
        cin>>data;
        insertAtEnd(head2,data);
    }
    

    

    // printLL(head2);

     node* newHead = mergingTwoLL(head1, head2);

    printLL(newHead);

    

    return 0;
}
