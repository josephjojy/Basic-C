#include<stdio.h>
void main()
{
 int i,j,m,n,k=0;
 printf("Enter size of matrix:");
 scanf("%d %d",&m,&n);
 int A[m][n],B[m*n/2][3];
 printf("Enter matrix elements:\n");
 for(i=0;i<m;i++)
 { 
  for(j=0;j<n;j++)
   scanf("%d",&A[i][j]);
 }
 printf("Original Matrix:\n");
 for(i=0;i<m;i++)
 { 
  for(j=0;j<n;j++)
   printf("%d\t",A[i][j]);
  printf("\n"); 
 }
 B[0][0]=m;
 B[0][1]=n;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  { 
    if(A[i][j]!=0)
    {
     k++;
     B[k][0]=i;
     B[k][1]=j;
     B[k][2]=A[i][j];     
    }
  }
 }
 printf("Sparce Matrix:\n");
 B[0][2]=k;
 for(i=0;i<=k;i++)
 { 
  for(j=0;j<3;j++)
   printf("%d\t",B[i][j]);
  printf("\n"); 
 }
}
