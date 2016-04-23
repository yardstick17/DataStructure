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
struct node *BSTrange(struct node *Root,int low,int high)
 {    

 	 if(Root==NULL)
 	 return NULL;
 	 
 	 Root->left  =  BSTrange(Root->left,low,high);
 	 Root->right =  BSTrange(Root->right,low,high);
	  if(Root->data < low )
	  { 
	     struct node *tmp = Root->right;
	     free(Root);
	     return tmp;
         }
 	  if(Root->data > high)
 	  { 
 	  
 	    struct node *tmp = Root->left;
 	   free(Root);
 	    return tmp;
		}
 	  return Root;
 }

int main()
{
   struct node *Root = NewNode(50);
   Insert(Root,41);
   Insert(Root,9);
   Insert(Root,83);
   Insert(Root,90);
   Insert(Root,144);
   Insert(Root,8);
   
   inorder(Root);
   cout<<"\n";
   BSTrange(Root,15,50);
   inorder(Root);
 
  
   
   





return 0;
}

