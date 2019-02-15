#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node* next;
}*FIRST=NULL,*current=NULL,*n,*current1=NULL,*current2=NULL;
int c,rem,ele;

void display()
{
 current2=FIRST;
 printf("\nList:");
 while(current2!=NULL)
 {
   printf("%d ",current2->data);
   current2=current2->next;
 }
 printf("\n");
}


void insert()
{
 n=(struct node*)malloc(sizeof(struct node));
 printf("Enter the data:");
 scanf("%d",&n->data);
 n->next=NULL;
 if(FIRST==NULL)
  { FIRST=n;current=FIRST;}
 else
 { current->next=n;
   current=n;
 }
 display();
 
}


void remdupl()
{
 current=FIRST;
 while(current!=NULL)
 {
  current1=current;
  rem=current->data;
  while(current1->next!=NULL)
  {
    if(rem==current1->next->data)
      {
          current1->next=current1->next->next;
      }
    current1=current1->next;
  }
  current=current->next;
 }display();
}

void remfl()
{display();
 printf("Enter the element:");
 scanf("%d",&ele);
 current=FIRST;
 int flag=0,count=0,sc=-1;
 while(current->next!=NULL)
 { 
   if(FIRST->data==ele)
   {flag=1;
    FIRST=FIRST->next;}
   else if(current->next->data==ele)
   { 
     if(flag==0)
      {flag=1;
       current->next=current->next->next;}
     else
      sc=count;
   }
   count=count+1;
 current=current->next;
 }
 current=FIRST;
 for(int i=0;i<sc;i++)
  current=current->next;
 current->next=current->next->next;
 display();
}

void main()
{
 do
 {
 printf("Enter\n1-Insertion\n2-Remove Duplicate\n3-Remove First and Last Occurance\n4-Display\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:insert();break;
  case 2:remdupl();break;
  case 3:remfl();break;
  case 4:display();break;
  default:printf("Invalid Input");
 }
 printf("\nEnter 0 to exit:");
 scanf("%d",&c);
 }while(c!=0);
}
