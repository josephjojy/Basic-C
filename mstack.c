#include<stdio.h>
void main()
{ 
 int topa=-1,size,f=1,ch,c,item,i;
 printf("Enter size:");
 scanf("%d",&size);
 int A[size],topb=size;
 while(f==1)
 {
  printf("\nEnter\n1-Stack A\n2-Stack B\n3-Exit\n");
  scanf("%d",&c);
  if(c==1)
  {
   printf("\nEnter\n1-Push\n2-Pop\n3-Display\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
         {
           if(topa==topb-1)
             printf("Stack Overflow\n");
           else
           {
             topa++;
             printf("Enter item to be pushed:");
             scanf("%d",&item);
             A[topa]=item; 
             printf("Item pushed\n");
             printf("Stack A: ");
             for(i=0;i<=topa;i++)
              printf("%d ",A[i]);
             printf("\n");
           }
         }break;
    case 2:
         {
           if(topa==-1)
             printf("Stack Underflow\n");
           else
             {topa--;
              printf("Item popped\n");
              printf("Stack A: ");
             for(i=0;i<=topa;i++)
              printf("%d ",A[i]);
             printf("\n");}
         }break;
    case 3:
         {
           if(topa==-1)
             printf("No elements\n");
           else
           {
             printf("Stack A: ");
             for(i=0;i<=topa;i++)
              printf("%d ",A[i]);
             printf("\n");
           } 
         }break;
    default:printf("Invalid Input\n");
   }
  }
  else if(c==2)
  {
   printf("\nEnter\n1-Push\n2-Pop\n3-Display\n");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1:
         {
           if(topa==topb-1)
             printf("Stack Overflow\n");
           else
           {
             topb--;
             printf("Enter item to be pushed:");
             scanf("%d",&item);
             A[topb]=item; 
             printf("Item pushed\n");
             printf("Stack B: ");
             for(i=size-1;i>=topb;i--)
              printf("%d ",A[i]);
             printf("\n");
           }
         }break;
    case 2:
         {
           if(topb==size)
             printf("Stack Underflow\n");
           else
             {topb++;
              printf("Item popped\n");
              printf("Stack B: ");
             for(i=size-1;i>=topb;i--)
              printf("%d ",A[i]);
             printf("\n");}
         }break;
    case 3:
         {
           if(topb==size)
             printf("No elements\n");
           else
           {
             printf("Stack B: ");
             for(i=size-1;i>=topb;i--)
              printf("%d ",A[i]);
             printf("\n");
           } 
         }break;
    default:printf("Invalid Input\n");
   }
  }
  else
     f=0;
 }
}
