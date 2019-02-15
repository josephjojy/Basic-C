#include<stdio.h>
void main()
{
 int i,j,k,a,b;
 printf("Enter the number of nonzero in sparse matrix A:");
 scanf("%d",&a);
 printf("Enter the number of nonzero in sparse matrix B:");
 scanf("%d",&b);
 int A[a][3],B[b][3],C[a+b][3];
 printf("Enter number of rows and coloumns:");
 scanf("%d %d",&A[0][0],&A[0][1]);
 B[0][0]=C[0][0]=A[0][0];
 B[0][1]=C[0][1]=A[0][1];
 A[0][2]=a;
 B[0][2]=b;
 printf("Enter sparse matrix A:\n");
 for(i=1;i<=a;i++)
 { 
   printf("Row number:");
   scanf("%d",&A[i][0]);
   printf("Colounm number:");
   scanf("%d",&A[i][1]);
   printf("Non Zero number:");
   scanf("%d",&A[i][2]);
 }
 for(i=0;i<=a;i++)
 { 
  for(j=0;j<3;j++)
   printf("%d\t",A[i][j]);
  printf("\n"); 
 }
 printf("Enter sparse matrix B:\n");
 for(i=1;i<=b;i++)
 { 
   printf("Row number:");
   scanf("%d",&B[i][0]);
   printf("Colounm number:");
   scanf("%d",&B[i][1]);
   printf("Non Zero number:");
   scanf("%d",&B[i][2]);
 }
 for(i=0;i<=b;i++)
 { 
  for(j=0;j<3;j++)
   printf("%d\t",B[i][j]);
  printf("\n"); 
 }
 i=j=k=1;
 while((i<=a)&&(j<=b))
 {
  if(A[i][0]==B[j][0])
  {
   if(A[i][1]==B[j][1])
   {
    if(A[i][2]+B[j][2]!=0)
    {
     C[k][0]=A[i][0];
     C[k][1]=A[i][1];
     C[k][2]=A[i][2]+B[j][2];
     k++;
    }
    i++;j++;
   }
   else if(A[i][1]<B[j][1])
   {
    C[k][0]=A[i][0];
    C[k][1]=A[i][1];
    C[k][2]=A[i][2];
    k++;i++;
   }
   else
   {
    C[k][0]=B[j][0];
    C[k][1]=B[j][1];
    C[k][2]=B[j][2];
    k++;j++;
   }
  }
  else if(A[i][0]<B[j][0])
   {
    C[k][0]=A[i][0];
    C[k][1]=A[i][1];
    C[k][2]=A[i][2];
    k++;i++;
   }
   else
   {
    C[k][0]=B[j][0];
    C[k][1]=B[j][1];
    C[k][2]=B[j][2];
    k++;j++;
   }
 }
 while(i<=a)
 {
    C[k][0]=A[i][0];
    C[k][1]=A[i][1];
    C[k][2]=A[i][2];
    k++;i++;
 }
 while(j<=b)
 {
    C[k][0]=B[j][0];
    C[k][1]=B[j][1];
    C[k][2]=B[j][2];
    k++;j++;
 }

 printf("Sparse Matrix sum:\n");
 C[0][2]=k-1;
 for(i=0;i<k;i++)
 { 
  for(j=0;j<3;j++)
   printf("%d\t",C[i][j]);
  printf("\n"); 
 }
}

