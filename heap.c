#include<stdio.h>
void main()
{
 int i,n,m,temp,flag=1;
 printf("Enter Number of terms(odd numbers):");
 scanf("%d",&n);
 m=n;
 int a[n];
 printf("Enter numbers:");
 for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
 while(flag!=0)
 {flag=0;
  for(i=n;i>0;i=i-2)
  {
     if(a[i]>a[i/2]&&a[i-1]<a[i])
     {  temp=a[i];
        a[i]=a[i/2];
        a[i/2]=temp;flag=1;
     }  
     else if((a[i-1]>a[i/2]&&a[i-1]>a[i]))
     {  temp=a[i-1];
        a[i-1]=a[i/2];
        a[i/2]=temp;flag=1;
     }  
  }
   temp=a[n];
   a[n]=a[1];
   a[1]=temp;n=n-1;
 }
 printf("\nSorted\n");
 for(i=1;i<=m;i++)
  printf(" %d ",a[i]);
}
