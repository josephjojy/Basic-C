#include<stdio.h>
int A[100],c,p,n,i,len,v,a;
void display()
{
          printf("\n\n");
           int j=2;
           for(i=1;i<=len;i++)
           {
             if(A[i]==0)
                printf(" \t",A[i]);
             else 
              printf("%d\t",A[i]);
             if(i==j-1||i==1)
             {
                printf("\n");
                j=j*2;
             }
           }
}  
void main()
{
 printf("Enter Root Value:");
 scanf("%d",&A[1]);
 for(i=2;i<100;i++)
    A[i]=NULL;
 len=1;
 do
 {
 printf("\nEnter\n1-Insert\n2-Delete\n3-Search\n4-Display\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:
        {
          printf("\nEnter the parent node:");
          scanf("%d",&p);
          printf("Enter 1-Left 2-Right\t:");
          scanf("%d",&n);
          printf("Enter the value:");
          scanf("%d",&v);
          for(i=1;i<=len;i++)
          {
             if(p==A[i])
                break;
          }
          if(p==A[i])
          {
             if(n==1&&A[2*i]==0)
                A[2*i]=v;
             if(n==2&&A[2*i+1]==0)
                 A[2*i+1]=v;
             if(len<2*i+1)
                len=2*i+1;
          }
          else
            printf("\nNOT FOUND\n");
        }break;
   case 2:
         {
            printf("\nEnter the value:");
            scanf("%d",&v);
            for(i=1;i<=len;i++)
            {
               if(v==A[i])
                 break;
            } 
             if(v==A[i]&&A[i*2]==NULL&&A[i*2+1]==NULL)
                A[i]=NULL;
             else
                printf("\nNot Found OR Not Possible\n");
         } break;
   case 3:
         {
           printf("\nEnter the value:");
            scanf("%d",&v);
            for(i=1;i<=len;i++)
            {
               if(v==A[i])
                 break;
            } 
             if(v==A[i])
                printf("\nFound\n");
             else
                printf("\nNOT FOUND\n");
         }break;
   case 4:
         {
           
         }
     }
  display();
  printf("\nEnter 0 to exit:");
  scanf("%d",&a);
 }while(a!=0);  
}

