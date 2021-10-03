/* Program for implementation of simple queue  */

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
int que[5];
int front=-1,rear=-1;
int choice;
char ch;
int item;
void insert();
void del();
void traverse();
void main()
{
  do{
      clrscr();
      printf("\n 1-Insert");
      printf("\n 2-Delete");
      printf("\n 3-Traverse");
      printf("\n Enter your choice::");
      scanf("%d",&choice);
      switch(choice)
      {
     case 1:insert();
        break;
     case 2:del();
        break;
     case 3:traverse();
        break;
     default:printf("Invalid choice");
      }
      printf("\n Do u wish to continue...");
      fflush(stdin);
      scanf("%c",&ch);
    }while(ch == 'y'||ch == 'Y');
getch();
}
void insert()
{
   if(rear==MAXSIZE-1)
   {
     printf("Queue Overflow");
     return;
   }
   else
   {
      printf("\nEnter a value to insert:: ");
      scanf("%d",&item);
      if(front==-1)
          front=rear=0;
      else
          rear=rear+1;
      que[rear]=item;

   }
   return;
}

void del()
{
    if(front==-1)
    {
      printf("\nqueue is empty");
      return;
    }
    else
    {
       item=que[front];
    }
    if(front==rear)
    {
    front=rear=-1;
    }
    else
    {
       front=front+1;
    }
       printf("\n The deleted value is %d",item);
}

void traverse()
{
int i;
if(front<0)
    {
      printf("\nqueue is empty");
      return;
    }
    else
    {
      for(i=front;i<=rear;i++)
      {
     printf("\n%d",que[i]);
      }
    }
}
