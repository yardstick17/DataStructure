			/* AK_47*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string.h>
#include<queue>
#include<stdlib.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define V(x) vector<x>
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
struct node {
	int data;
	struct node *left,*right;
	 
};

struct node *NewNode(int item)
{
	 struct node *tmp = (struct node *)malloc(sizeof(struct node));
	 tmp->data  = item;
	 tmp->left = tmp->right = NULL;
	 return tmp;
	 
	 
}
struct node  *Insert(struct node *Root,int item)
{
	 if(Root==NULL)
	 return NewNode(item);
	 
	 if(Root->data>item)
	 Root->left = Insert(Root->left,item);
	 else if(item > Root->data)
	 Root->right  = Insert(Root->right,item);
   return Root;
}
	 
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void FixUTIL(struct node *Root, struct node **first, struct node **middle,struct node **last,struct node **prev)
{
	  
	   if(Root!=NULL)
	   {
	   
	    
	    FixUTIL(Root->left,first,middle,last,prev);
	    if(*prev!=NULL && (*prev)->data > Root->data)
	     {
	     	  if(!(*first))
			   {
			   *first = *prev ;
	     	  *middle = Root;
	          }
	           else
	    	 *last = Root;
	    }
	    
	     
		*prev = Root;
	    FixUTIL(Root->right,first,middle,last,prev);
	   }
	   
}

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}


void FixBST(struct node *Root)
 {
 	 struct node *first,*middle,*last,*prev;
 	 first = middle = last = prev= NULL ;
 	 FixUTIL(Root,&first,&middle,&last,&prev);
     
	 
	 if( first && last )
        swap( &(first->data), &(last->data) );
     else if( first && middle ) // Adjacent nodes swapped
        swap( &(first->data), &(middle->data) );
 
    // else nodes have not been swa
 	  
 	 
 }
int main()
{
   struct node *root = NewNode(6);
    root->left        = NewNode(10);
    root->right       = NewNode(2);
    root->left->left  = NewNode(1);
    root->left->right = NewNode(3);
    root->right->right = NewNode(12);
    root->right->left = NewNode(7);
   inorder(root);
   cout<<"\n";
   FixBST(root);
    inorder(root);

  
   
   





return 0;
}

