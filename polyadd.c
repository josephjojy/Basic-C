#include<stdio.h>
#include<malloc.h>
struct node
{
 int coef;
 int exp;
 struct node *next;
};
struct node *first1,*first2;
struct node *n,*current,*x,*y;
int a;
void display(struct node *first)
{
 printf("\n");
 current=first;
 while(current->next!=NULL)
 {
   printf("%dx^%d + ",current->coef,current->exp);
   current=current->next;
 }
 printf("%dx^%d \n\n",current->coef,current->exp);
 
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
    if(x->exp==y->exp)
    {  if(x->next==NULL&&y->next==NULL)
           printf("%dx^%d  \n\n",(x->coef+y->coef),x->exp);
       else
           printf("%dx^%d + ",(x->coef+y->coef),x->exp);
       x=x->next;
       y=y->next;      
    }   
    else if(x->exp>y->exp)
    {
       printf("%dx^%d + ",x->coef,x->exp);
       x=x->next;
    }
    else
    {
       printf("%dx^%d + ",y->coef,y->exp);
       y=y->next;
    }
 }
 while(x!=NULL)
 {
   printf("%dx^%d  \n\n",x->coef,x->exp);
   x=x->next;
 }
  while(y!=NULL)
 {
   printf("%dx^%d  \n\n",y->coef,y->exp);
   y=y->next;
 }
} 
void main()
{ 
  first1=first2=NULL;
  printf("First Polynomial\n");
    accept(&first1);
  printf("Second Polynomial\n");
    accept(&first2);
  sum();
}
