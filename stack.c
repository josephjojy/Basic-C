#include<stdio.h>
void main()
{ 
 int top=-1,n,f=1,ch,item,i;
 printf("Enter size:");
 scanf("%d",&n);
 int A[n];
 while(f==1)
 {
  printf("\nEnter\n1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
         {
           if(top==n-1)
             printf("Stack Overflow\n");
           else
           {
             top++;
             printf("Enter item to be pushed:");
             scanf("%d",&item);
             A[top]=item; 
             printf("Item pushed\n");
              printf("Stack: ");
             for(i=0;i<=top;i++)
              printf("%d ",A[i]);
             printf("\n");
           }
         }break;
   case 2:
         {
           if(top==-1)
             printf("Stack Underflow\n");
           else
             {top--;
              printf("Item popped\n");
               printf("Stack: ");
             for(i=0;i<=top;i++)
              printf("%d ",A[i]);
             printf("\n");}
         }break;
   case 3:
         {
           if(top==-1)
             printf("No elements\n");
           else
             printf("Peeked item:%d \n",A[top]);
         }break;
   case 4:
         {
           if(top==-1)
             printf("No elements\n");
           else
           {
             printf("Stack: ");
             for(i=0;i<=top;i++)
              printf("%d ",A[i]);
             printf("\n");
           } 
         }break;
   case 5:
         f=0;
         break;
   default:printf("Invalid Input\n");
  }
 }
}
