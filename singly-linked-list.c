// All operations perfomed on singly linked list includes creation ,insertion at first, last, and middle, deletion at first, last and middle


#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
    
};
typedef struct node node;

node *first=NULL;
node *temp=NULL;
node *pretemp=NULL;
node *ptr=NULL;

void create(){
    temp=(node*)malloc(sizeof(node));
    printf("enter data for the node:");
    scanf("%d",&temp->data);
    temp->nxt=NULL;
    if(first==NULL)
    {
        first=temp;
    }
    else{
        ptr->nxt=temp;
    }
    ptr=temp;
}

void display(){
    printf("linked lists inputted is:");
    for(temp=first;temp!=NULL;temp=temp->nxt)
    {
        printf("%d \t",temp->data);
        
    }
    printf("\n");
}

void insertfst()
{  
    ptr=(node*)malloc(sizeof(node));
    printf("enter the value you wanna insert:");
    scanf("%d",&ptr->data);
    ptr->nxt=first;
    first=ptr;
    ptr=(node*)malloc(sizeof(node));
    
}

void insertlast()
{
    ptr=(node*)malloc(sizeof(node));
    printf("enter the value you wanna insert:");
    scanf("%d",&ptr->data);
    for(temp=first;temp->nxt!=NULL;temp=temp->nxt)
    {
    }
    temp->nxt=ptr;
    ptr->nxt=NULL;
}

void deletefst()
{
    temp=first;
    first=first->nxt;
    free(temp);
}

void deletelast()
{
    for(temp=first;temp->nxt!=NULL;temp=temp->nxt)
    {
        pretemp=temp;
    }
    
    pretemp->nxt=NULL;
    free(temp);
}

void insertval()
{
    int val;
    printf("enter the value:");
    scanf("%d",&val);
    for(temp=first;temp->data!=val;temp=temp->nxt)
    {
        pretemp=temp;
     
     }
    ptr= (node*)malloc(sizeof(node));
    printf("enter data:");
    scanf("%d",&ptr->data);
    ptr->nxt=temp;
    pretemp->nxt=ptr;
 
}

void deleteval()
{
    int val;
    printf("enter the value you wanna delete: ");
    scanf("%d",&val);
    for(temp=first;temp->data!=val;temp=temp->nxt)
    {
        pretemp=temp;
     
     }
     pretemp->nxt=temp->nxt;
     free(temp);
}

void insertpos()
{
    int i=1,pos;
    printf("enter the position:");
    scanf("%d",&pos);
    for(pretemp=first;pretemp!=NULL;pretemp=pretemp->nxt)
    {
        if(i==(pos-1))
        break;
        else
        i++;
    }
    temp=pretemp->nxt;
    ptr= (node*)malloc(sizeof(node));
    printf("enter the value you want to insert:");
    scanf("%d",&ptr->data);
    ptr->nxt=temp;
    pretemp->nxt=ptr;
    
}
void deletepos()
{
    int i=1,pos;
    printf("enter the position:");
    scanf("%d",&pos);
    for(pretemp=first;pretemp!=NULL;pretemp=pretemp->nxt)
    {
        if(i==(pos-1))
        break;
        else
        i++;
    }
   
    temp=pretemp->nxt;
    pretemp->nxt=temp->nxt;
    free(temp);
}
void main()
{
   int c;
   do{
       printf("enter \n 1 to create \n 2 to display \n 3 to insert from first \n 4 to insert from last \n 5 to delete from first \n 6 to delete from last \n 7 to insert by value \n 8 to insert by position \n 9 to delete by value \n 10 to delete by position:");
       scanf("%d",&c);
       switch(c)
            {
                case 1:create();
                break;
                
                case 2:display();
                break;
                
                case 3:insertfst();
                break;
                
                case 4:insertlast();
                break;
                
                case 5:deletefst();
                break;
                
                case 6:deletelast();
                break;
                
                case 7:insertval();
                break;
                
                case 8:insertpos();
                break;
                
                case 9:deleteval();
                break;
                
                case 10:deletepos();
                break;
                
                default:printf("please choose the valid option.");
            }
        
   }while(1);
   free (ptr);
   free (temp);
}

