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
#include<limits>
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
struct node *LCA(struct node *Root,int n1,int n2)
{
	 if(Root== NULL)
	 return NULL;
	 if(Root->data > n1 && Root->data >n2)// || Root->data < n1 && Root->data < n1)
	 return LCA(Root->left,n1,n2);
	 
	 if(Root->data < n1 && Root->data < n2)
	 return LCA(Root->right,n1,n2);
	 
	 return Root;
}

int main()
{
   struct node *Root = NewNode(20);
    Root->left               = NewNode(8);
    Root->right              = NewNode(22);
    Root->left->left         = NewNode(4);
    Root->left->right        = NewNode(12);
    Root->left->right->left  = NewNode(10);
    Root->left->right->right = NewNode(14);
   
   inorder(Root);
   cout<<"\n";
  cout<<LCA(Root,14,12)->data;
 
  
   
   





return 0;
}

