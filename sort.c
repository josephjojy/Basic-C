#include<stdio.h>
int m;
int Partition(int A[100],int beg,int end)
{
 int loc=beg;
 while(1)
 {
   while(A[loc]<=A[end]&&loc!=end)
	end=end-1;
   if(loc==end)
 	return loc;
   int temp=A[loc];
   A[loc]=A[end];
   A[end]=temp;
   loc=end;
   while(A[loc]>=A[beg]&&loc!=beg)
	beg=beg+1;
   if(loc==beg)
	return loc;
   temp=A[loc];
   A[loc]=A[beg];
   A[beg]=temp;
   loc=beg;
   printf("\n");
   for(int z=1;z<=m;z++)
           printf(" %d ",A[z]);
   printf("\n");
 }
}
void QuickSort(int A[100],int beg,int end)
{
 if(beg<end)
 {
  int x=Partition(A,beg,end);
  QuickSort(A,beg,x-1);
  QuickSort(A,x+1,end);
 }
}
void MergeArray(int A[100],int beg,int mid, int end)
{
 int i,j,k,B[100];
 for(i=beg;i<=end;i++)
   B[i]=A[i];
 i=beg;j=mid+1;k=beg;
 while(i<=mid&&j<=end)
 {
   if(B[i]<=B[j])
   {
     A[k]=B[i];
     i=i+1;k=k+1;
   }
   else
   {
     A[k]=B[j];
     j=j+1;k=k+1;
   }
 }
 if(i<=mid)
 {
  while(i<=mid)
  {
   A[k]=B[i];
   i=i+1;k=k+1;
  }
 }
 else
 {
  while(j<=end)
  {
   A[k]=B[j];
   j=j+1;k=k+1;
  }
 }
 printf("\n");
   for(int z=1;z<=m;z++)
           printf(" %d ",A[z]);
   printf("\n");
}
void MergeSort(int A[100],int beg,int end)
{
 if(beg<end)
 {
  int mid=(beg+end)/2;
  MergeSort(A,beg,mid);
  MergeSort(A,mid+1,end);
  MergeArray(A,beg,mid,end);
 }
}

void main()
{
 int i,n,temp,flag=1,c;
 printf("Enter Number of terms:");
 scanf("%d",&n);
 m=n;
 int A[n];
 printf("Enter numbers:\n");
 for(i=1;i<=n;i++)
  scanf("%d",&A[i]);
 printf("Enter\n1-Quick Sort\n2-Merge Sort\n3-Heap Sort\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:
         {
          QuickSort(A,1,n);
          printf("\nSorted Array:");
          for(i=1;i<=m;i++)
           printf(" %d ",A[i]);break;
         }
  case 2:
        {
          MergeSort(A,1,n);
          printf("\nSorted Array:");
          for(i=1;i<=m;i++)
           printf(" %d ",A[i]);break;
        }
  case 3:
        {
         while(flag!=0)
	 {flag=0;
	  for(i=n;i>0;i=i-2)
         {
           if(A[i]>A[i/2]&&A[i-1]<A[i])
           {   temp=A[i];
               A[i]=A[i/2];
               A[i/2]=temp;flag=1;
           }  
           else if((A[i-1]>A[i/2]&&A[i-1]>A[i]))
           {  temp=A[i-1];
             A[i-1]=A[i/2];
             A[i/2]=temp;flag=1;
           }  
          }
           temp=A[n];
           A[n]=A[1];
           A[1]=temp;n=n-1;
           printf("\n");
           for(int z=1;z<=m;z++)
              printf(" %d ",A[z]);
           printf("\n");
          }
          printf("\nSorted\n");
          for(i=1;i<=m;i++)
           printf(" %d ",A[i]);
        }break;
 }
}
