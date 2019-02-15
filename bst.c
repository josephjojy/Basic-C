#include<stdio.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *left,*right;
};
int c,ch,d,a=1,x,flag;
struct node *root=NULL;
struct node *n,*current,*p,*c1;


void Delete(int dd)
{
           current=root;
           flag=0;
            while(current!=NULL&&flag==0)
            {
               if(dd<current->data)
               {
                   p=current;
                   current=current->left;
               }
               else if(dd>current->data)
               {
                   p=current;
                   current=current->right;
               }
               else
                  flag=1;  
            }
            if(flag==1)
            {
                if(current->left==NULL&&current->right==NULL)
                {
                    if(p->left==current)
                        p->left=NULL;
                    else
                        p->right=NULL;
                }
                else if(current->left==NULL||current->right==NULL)
                {
                    if(p->left==current)
                    {
                        if(current->left==NULL)
                            p->left=current->right;
                        else
                            p->left=current->left;
                    }
                    else
                    {
                        if(current->left==NULL)
                            p->right=current->right;
                        else
                            p->right=current->left;
                    }
                }
                else
                {
                    c1=current->left;
                    while(c1->right!=NULL)
                        c1=c1->right;
                    x=c1->data;
                    printf("\n%d\n",x);
                    Delete(x);
                    p->data=x;
                }
            }
            else
              printf("Not found");
}

void inorder(struct node* p)
{
   if(p!=NULL)
   {
     inorder(p->left);
     printf(" %d ",p->data);
     inorder(p->right);
   }
}
void preorder(struct node* p)
{
   if(p!=NULL)
   {
     printf(" %d ",p->data);
     preorder(p->left);
     preorder(p->right);
   }
}
void postorder(struct node* p)
{
   if(p!=NULL)
   {
     postorder(p->left);
     postorder(p->right);
     printf(" %d ",p->data);
   }
}




int max_height(struct node* node)
 	  {
	   int l_depth;
	   int r_depth;
	 
 	   if (node==NULL)
             return (0);
            else 
            { 
 	     l_depth = max_height (node->left); 
	     r_depth = max_height (node->right); 
 	     if (l_depth > r_depth) 
 	       return (l_depth + 1);
  	      else 
 	       return (r_depth + 1);	     
           }   
         }               

void main()
{ 
 do
 {
  printf("\nEnter\n1-Insert\n2-Delete\n3-Traversal\n4-Search\n5-Height\n");
  scanf("%d",&c);
  switch(c)
  {
   case 1:
         {
            printf("Enter the data:");
            scanf("%d",&d);
            n=(struct node*)malloc(sizeof(struct node));
            n->data=d;
            n->left=NULL;
            n->right=NULL;
            if(root==NULL)
               root=n;
            else
            {
               current=root;
               while(current!=NULL)
               {
                 if(current->data>n->data)
                 {
                    if(current->left==NULL)
                          {current->left=n;break;}
                    else
                       current=current->left;
                 }
                 else
                 {
                    if(current->right==NULL)
                          {current->right=n;break;}
                    else
                          current=current->right;
                 }
               }
            }                        
         }break;
   case 2:
         {
            printf("Enter data to be deleted:");
            scanf("%d",&d);
            Delete(d);
         }break;
   case 3:
         {
            printf("\nInorder:");
            inorder(root);
            printf("\nPreorder:");
            preorder(root);
            printf("\nPostorder:");
            postorder(root);
         }break;
   case 4:
         {
            printf("Enter data to be Searched:");
            scanf("%d",&d);
            current=root;
            flag=0;
            while(current!=NULL&&flag==0)
            {
               if(d<current->data)
                   current=current->left;
               else if(d>current->data)
                   current=current->right;
               else
                  flag=1;  
            }
            if(flag==1)
                printf("Found");
            else
                printf("Not Found");
         }break;
   case 5:
         {
 	   int h=max_height(root);
           printf("\nHeight=%d\n",h);
 	 }break;
     }
   printf("\nEnter 0 to exit:");
  scanf("%d",&a);
 }while(a!=0);  
 }

