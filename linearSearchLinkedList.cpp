#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    void display(node *p)
    {
        cout << "linked list : " << endl;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
 
    node *search(node *p, int key)
    {
        while (p != NULL)
        {
            if (key == p->data)
            {
                return p;
               
            }
             p = p->next;
         } 
            
                return NULL;
            
        
    }
};
int main()
{
    cout << "enter the no of elements in the linked list : " << endl;
    int n, x;
    cin >> n;
    cout << "enter the " << n << " elements " << endl;
     cin >> x;
    cout<<"enter key : " ;
    int key;
    cin>>key;
   
    node *first = new node;
    node *p, *temp;
    first->data = x;
    first->next = NULL;
    temp = first;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        p = new node;
        p->data = x;
        p->next = NULL;
        temp->next = p;
        temp = p;
    }

    
     node().display(first);
    
    cout << endl;
    node* element = node().search(first,key);
   if(!element)
   cout<<"element is not found \n";
   else
   cout<<"element found \n";    
    return 0;
}