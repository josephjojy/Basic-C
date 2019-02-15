#include<stdio.h>
void main()
{
 printf("Enter the number of nonzero in sparse matrix:");
 scanf("%d",&a);
 int A[a][3];
 printf("Enter number of rows and coloumns:");
 scanf("%d %d",&A[0][0],&A[0][1]);
 A[0][2]=a;
 printf("Enter sparse matrix:\n");
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
}
