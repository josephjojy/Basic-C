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
            printf("\nEnter\n1-Beginning\n2-End\n3-Before a data\n");
            scanf("%d",&c);
            switch(c)
            {
              case 1:
                     {
                       if(first==NULL)
                         first=n;
                       else
                       {
                         n->next=first;
                         first=n;
                       }
                     }break;
              case 2:
                     {
                       if(first==NULL)
                         first=n;
                       else
                       {
                         current=first;
                         while(current->next!=NULL)
                            current=current->next;
                         current->next=n;
                       }
                     }break;
              case 3:
                     {
                       printf("Enter data before which it should be inserted:");
                       scanf("%d",&p);
                       current=first;
                       if(current->data==p)
                       {  n->next=first;
                         first=n;}
                       else
                      {
                       while(1)
                       {  
                           if(current->next->data==p) 
                            {  n->next=current->next;
                               current->next=n;break;}
                           if(current->next==NULL)
                              {printf("Not found"); break;}
                          current=current->next;
                       }
                      }
                        
                     }  break;
              default:printf("\nInvalid Input\n");       
            }display();
          }break;
   case 2:
          {
            if (first==NULL)
              printf("No elements to delete\n");
            else
            {printf("\nEnter\n1-Beginning\n2-End\n3-A data\n");
            scanf("%d",&c);
            switch(c)
            {
              case 1:
                    {
                      current=first;
                      first=current->next; 
                     }break;
              case 2:
                     {
                        current=first;
                        while(current->next->next!=NULL)
                             current=current->next;
                        current->next=NULL;
                     }break;
              case 3:
                     {
                       printf("Enter data to be deleted:");
                       scanf("%d",&p);
                       current=first;
                       if(current->data==p)
                         first=current->next; 
                       else
                       {
                        while(1)
                        {   
                           if(current->next->data==p)
                             { current->next=current->next->next;break;} 
                            if(current->next==NULL)
                               {printf("Not Found");break;}                           
                             current=current->next;
                        }
                       }
                     }break;
              default:printf("\nInvalid Input\n");      
            }display();
          }}break;
   case 3:display();break;
   default:printf("\n Invalid Input\n");
  }
  printf("\nDo you want to continue(1/0)?:");
  scanf("%d",&a);
 }
}
