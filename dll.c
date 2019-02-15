#include<stdio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *prev,*next;
};
int c,ch,d,a=1;
struct node *first=NULL;
struct node *last=NULL;
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
  while(a!=0)
  {
     printf("\nEnter\n1-Insert\n2-Delete\n3-Display\n");
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
            n->prev=NULL;
            printf("\nEnter\n1-Beginning\n2-End\n3-After a data\n");
            scanf("%d",&c);
            switch(c)
            {
              case 1:
                     {
                       if(first==NULL&&last==NULL)
                         first=last=n;
                       else
                       {
                         n->next=first;
                         first->prev=n;
                         first=n;
                       }
                     }break;
              case 2:
                     {
                        if(first==NULL&&last==NULL)
                         first=last=n;
                        else
                        {
                          n->prev=last;
                          last->next=n;
                          last=n; 
                        }
                     }break;
              case 3:
                     {
                       current=first;
                       printf("Enter data after which it should be inserted:");
                       scanf("%d",&d);
                       while(current->data!=d&&current!=NULL)
                          current=current->next;
                       if(current->data==d)
                       {
                          n->prev=current;
                          n->next=current->next;
                          n->next->prev=n;
                          current->next=n;
                       }
                       else
                         printf("\nNOT FOUND\n");
                     }break;
             default:printf("\nINVALID INPUT\n");
            }display();break;
           }
      case 2:
            {
               if (first==NULL)
                   printf("No elements to delete\n");
               else
               {
                printf("\nEnter\n1-Beginning\n2-Before a data\n");
                scanf("%d",&c);
                switch(c)
                {
                  case 1:
                        {
                         current=first;
                         first=current->next; 
                         current->next->prev=NULL;
                        }break;
                  case 2:
                        {
                          current=last;
                          printf("Enter data before which it should be deleted:");
                          scanf("%d",&d);
                          while(current->data!=d&&current!=NULL)
                            current=current->prev;
                          if(current->data==d&&current->prev!=NULL)
                          {
                            current->prev=current->prev->prev;
                            if(current->prev!=NULL)
                              current->prev->next=current;
                            else
                              first =current;
                          }
                          else
                           printf("\nNOT FOUND\n");
                       }break;
                  default:printf("\nINVALID INPUT\n");
                 }display();       
                }
           }break; 
      case 3:
            {
             printf("\nEnter\n1-Forward\n2-Backward\n");
             scanf("%d",&c);
             switch(c)
             {
               case 1:display();break;
               case 2:
                     {
                         printf("\nList elements:");
                         current=last;
                         if(current==NULL)
                         printf("NO elements left");
                         while(current!=NULL)
                         {
                         printf(" %d ",current->data);
                         current=current->prev;
                         }printf("\n");
                     }break;
               default:printf("\nINVALID INPUT\n");
             }
            }break;
       default:printf("\nINVALID INPUT\n");
     }
   printf("\nDo you want to continue(1/0)?:");
   scanf("%d",&a);
  }
 }

