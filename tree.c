#include<stdio.h>
void main()
{
 int A[100],c,p,n,i,len,v,a;
 printf("Enter Root Value:");
 scanf("%d",&A[1]);
 for(i=2;i<100;i++)
    A[i]=NULL;
 len=1;
 do
 {
 printf("\nEnter\n1-Insert\n2-Display\n");
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
             if(n==1)
                A[2*i]=v;
             if(n==2)
                 A[2*i+1]=v;
             if(len<2*i+1)
                len=2*i+1;
          }
          else
            printf("\nNOT FOUND\n");
        }break;
  case 2:
         {
           printf("\n\n");
           int j=2;
           for(i=1;i<=len;i++)
           {
             for(int k=0;k<len/(j);k++)
                printf("\t");
             printf("%d\t",A[i]);
             if((i+1)%2==0)
                printf("\t");            
             if(i==j-1||i==1)
             {
                printf("\n");
                j=j*2;
             }
           }  
         }
     }
  printf("\nEnter 0 to exit:");
  scanf("%d",&a);
 }while(a!=0);  
}

