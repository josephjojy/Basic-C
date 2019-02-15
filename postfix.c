#include<stdio.h>
#include<math.h>
char e[100],s[100],p[100],chr;
int tops=0,a=0,b=1,i,k=0,t[100];
void evl();
int comp(char,int,int);
void push(char);
int pry(char);
void pop()
{
  printf("%c",s[tops]);
  p[k]=s[tops];
  k++;
  tops--;
}
void main()
{
 char c;
 s[0]='#';
 printf("Enter the expression:");
 scanf("%s",e);
 printf("Postfix expression:");
 for(i=0;e[i]!='\0';i++)
 {   
   c=e[i];
   if(c=='(')
     push(c);
   else if(c==')')
   {
     while(s[tops]!='(')
      pop();
     tops--;
   }
   else if((c>64 &&c<91)||(c>96 && c<123))
    { printf("%c",c);
     p[k]=c;
     k++;}
   else
    { 
      do
      {
       a=pry(c);
       b=pry(s[tops]);
       if(a>b)
         push(c);
       else
        pop();
      }while(b>=a);
    }    
 }
 for(i=tops;i>0;i--)
 { printf("%c",s[i]);
  p[k]=s[i];
  k++;}
  p[k]='\0';
 printf("\nDo you want to evaluate?(1/0):");
 scanf("%d",&i);
 if(i==1)
   evl();
}
void push(char c)
{
 tops++;
 s[tops]=c;
}
int pry(char c)
{
  switch(c)
  {
    case '#':return 1;
    case '(':return 1;
    case '-':return 2;
    case '+':return 2;
    case '*':return 3;
    case '/':return 3;
    case '^':return 4;
  }
}
void evl()
{ int sum=0;k=0;
 for(i=0;p[i]!='\0';i++)
 {
    chr=p[i];
    if((chr>64 &&chr<91)||(chr>96 && chr<123))
    {
      printf("%c=",chr);
      scanf("%d",&t[k]);
      k++;
    }
    else
    {
      sum=comp(chr,t[k-2],t[k-1]);
      k=k-2;
      t[k]=sum;k++;
    }
 }
 printf("Answer=%d",t[0]);
}
int comp(char ch,int x,int y)
{
   switch(ch)
  {
    case '-':return (x-y);
    case '+':return (x+y);
    case '*':return (x*y);
    case '/':return (x/y);
    case '^':return (int)pow((double)x,(double)y);
  }
}
