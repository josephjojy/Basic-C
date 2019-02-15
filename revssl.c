#include<stdio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *next;
};
int ch,c,d,p,a=1;
struct node *first=NULL;
struct node *n,*current;
void display()
{ printf("\nList elements:");
  current=first;
   if(current==NULL)
    printf("NO elements left");
  while(current!=NULL)
  {
    printf(" %d ",current->data);
    current=current->next;
  }printf("\n");
}
void main()
{
 while(a==1)
 {
 printf("\nEnter\n1-Insert\n2-Display Reverse\n");
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:
         {
            printf("Enter the data:");
            scanf("%d",&d);
            n=(struct node*)malloc(sizeof(struct node));
            n->data=d;
            n->next=NULL;
            if(first==NULL)
                first=n;
            else
            {
              current=first;
              while(current->next!=NULL)
                   current=current->next;
              current->next=n;
             }display();
          }break;
    case 2:
          {
            current=first;
            while(first!=NULL)
            {
              while(current->next!=NULL)
                current=current->next;
              printf("%d",current->data);
              current=NULL;
            }break;
          }
   }
    printf("\nDo you want to continue(1/0)?:");
    scanf("%d",&a);                  
 }
}
