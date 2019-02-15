#include<stdio.h>
#include<malloc.h>
struct node
{
 int coef;
 int exp;
 struct node *next;
};
struct node *first1,*first2,*first3,*first4;
struct node *n,*current,*x,*y,*z,*l;
int a;


void display(struct node *first)
{
 printf("\n");
 current=first;
 while(current->next!=NULL)
 { 
   if(current->exp==1)
    printf("%dx + ",current->coef);
   else if(current->exp==0)
    printf("%d + ",current->coef);
   else
    printf("%dx^%d + ",current->coef,current->exp);
   current=current->next;
 }
 if(current->exp==1)
    printf("%dx ",current->coef);
 else if(current->exp==0)
    printf("%d ",current->coef);
 else
    printf("%dx^%d ",current->coef,current->exp); 
  printf("\n");
}


void accept(struct node **first)
{
   do
  {
     n=(struct node*)malloc(sizeof(struct node));
     printf("Enter Coefficient:");
     scanf("%d",&(n->coef));
     printf("Enter Exponent:");
     scanf("%d",&(n->exp));
     n->next=NULL;
     if(*first==NULL)
         *first=n;
     else
         current->next=n;
     current=n;
     printf("Are there any more terms?(1/0):");
     scanf("%d",&a);
  } while(a!=0);
  display(*first);
}


void sum()
{
 printf("\nSum = ");
 x=first1;
 y=first2;
 while((x!=NULL)&&(y!=NULL))
 {
      n=(struct node*)malloc(sizeof(struct node));
      n->next=NULL;
    if(x->exp==y->exp)
    {  
       n->coef=x->coef+y->coef;
       n->exp=x->exp;
       x=x->next;
       y=y->next;      
    }   
    else if(x->exp>y->exp)
    {
       n->coef=x->coef;
       n->exp=x->exp;
       x=x->next;
    }
    else
    {
       n->coef=y->coef;
       n->exp=y->exp;
       y=y->next;
    }
    if(first4==NULL)
         first4=n;
    else
         current->next=n;
    current=n;
 }
 while(x!=NULL)
 {
   n=(struct node*)malloc(sizeof(struct node));
   n->next=NULL;
   n->coef=x->coef;
   n->exp=x->exp;
   x=x->next;
   current->next=n;
   current=n;
 }
  while(y!=NULL)
 {
   n=(struct node*)malloc(sizeof(struct node));
   n->next=NULL;
   n->coef=y->coef;
   n->exp=y->exp;
   y=y->next;
   current->next=n;
   current=n;
 }
 display(first4);
} 


void product()
{
  printf("\nProduct = ");
  x=first2;
  y=first1;
  while(x!=NULL)
  {
    while(y!=NULL)
    {
      n=(struct node*)malloc(sizeof(struct node));
      n->coef=x->coef*y->coef;
      n->exp=x->exp+y->exp;
      n->next=NULL;
      if(first3==NULL)
           first3=n;
      else
           current->next=n;
      current=n;
      y=y->next;
    }
    y=first1;
    x=x->next;
  }
  z=first3;
  while(z!=NULL)
  {
    l=z;
    while(l->next!=NULL)
    {
      if(z->exp==l->next->exp)
      {
        z->coef=z->coef+l->next->coef;
        l->next=l->next->next;
      }
      l=l->next;
    }
    z=z->next;
  } display(first3);
}


void main()
{ 
  first1=first2=first3=first4=NULL;
  printf("First Polynomial\n");
    accept(&first1);
  printf("\nSecond Polynomial\n");
    accept(&first2);
  sum();
  product();
}





