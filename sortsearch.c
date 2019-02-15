#include<stdio.h>
int a[100];
int c,n,i,j,ch,temp,num;
void display()
{ 
  printf("\n");
  for(int k=0;k<n;k++)
     printf(" %d ",a[k]);
   printf("\n");
}
void bubble()
{
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-i-1;j++)
   {display();
      if(a[j]>a[j+1])
      {
         temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
      }
   }
  }
}
void insertion()
{
  for(i=0;i<n;i++)
  {
    temp=a[i];
    for(j=i-1;(j>=0&&temp<a[j]);j--)
     a[j+1]=a[j];
    a[j+1]=temp;display();
  }
}
void selection()
{
  int min;
  for(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[min]>a[j])
        min=j;
    }
    temp=a[i];
    a[i]=a[min];
    a[min]=temp;display();
  }
}
void linear()
{
 for(i=0;i<n;i++)
 {
   if(a[i]==num)
     break;
 }
 if(i<n)
  printf("FOUND at %d\n",(i+1));
 else
  printf("NOT FOUND");
}
void binary()
{
  int l,f,m;
  l=n;
  f=0;
  do
  {
   m=(l+f)/2;
   if(a[m]==num)
      break;
   else if(a[m]>num)
      l=m-1;
   else
      f=m+1;
  }while(f<l);
  if(a[m]==num)
   printf("FOUND at :%d\n",(m+1));
  else
   printf("NOT FOUND");
}
void main()
{
 printf("Enter Number of terms:");
 scanf("%d",&n);
 printf("Enter terms:\n");
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 display();
 do
 {
  printf("Enter\n1-Sort\n2-Search\n");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
          {
            printf("Enter\n1-Bubble\n2-Insertion\n3-Selection\n");
            scanf("%d",&ch);
            switch(ch)
            {
              case 1:bubble();break;
              case 2:insertion();break;
              case 3:selection();break;
              default:printf("\nInvalid Input\n");
            }
          }break;
    case 2:
          {
            printf("Enter element to be searched:");
            scanf("%d",&num);
            printf("Enter\n1-Linear\n2-Binary\n");
            scanf("%d",&ch);
            switch(ch)
            {
              case 1:linear();break;
              case 2:binary();break;
              default:printf("\nInvalid Input\n");
             }
           }break;
    default:printf("\nInvalid Input\n");
  }
  printf("Do you want to continue?(1/0):");
  scanf("%d",&i);
 }while(i!=0);
}
