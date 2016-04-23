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
	 struct node *left;
	 struct node *right;
};

struct node *NewNode(int data)
 {
 	 struct node *New = (struct node *)malloc(sizeof(struct node));
 	 New->left = NULL;
 	 New->right = NULL;
 	 New->data = data;
 	 return New;
 }
int Height(struct node *Root)
  {
  	  if(Root==NULL)
  	  return 0;
  	  
  	  int lheight = Height(Root->left);
  	  int rheight = Height(Root->right);
  	  
	 if(lheight>rheight)
  	    return lheight+1;
     else
  	    return rheight+1;
  	  
  }
  
void TraverseLevel(struct node *Root, int Level)
   {
   	   if(Root==NULL)
   	   return;
		if(Level==0)
		 cout<<Root->data<<" ";
		else
		   TraverseLevel(Root->left, Level-1);
		   TraverseLevel(Root->right,Level-1);
  }
void LevelOrder(struct node *Root)
  {
  	  int height = Height(Root);
  	  for(int i = 0 ; i<height; i++)
  	    {
  	    	  TraverseLevel(Root,i);
  	    }
  }
  
  
void Inorder(struct node *Root)
   {
   	 if(Root==NULL)
   	 return;
   	 
   	 Inorder(Root->left);
   	 cout<<Root->data<<" ";
   	 Inorder(Root->right);
   	 
   }
void Preorder(struct node *Root)
    {
    	 if(Root==NULL)
    	 return ;
    	 cout<<Root->data<<" ";
   	     Preorder(Root->left); 
    	 Preorder(Root->right);
    	 
    	 
    	 
    }
void Postorder(struct node *Root)
     {
     	 if(Root==NULL)
     	 return;
     	 
     	 Postorder(Root->left);
     	 Postorder(Root->right);
     	 
     	 cout<<Root->data<<" ";
	 }
struct node *Sum(struct node *Root,int sum, int k)
 {
     
	 if(Root==NULL)//>left==NULL && Root->right == NULL)
	  	 return NULL ;
	  
 	   Root->left =  Sum(Root->left,sum + Root->data,k);
	    Root->right = Sum(Root->right,sum + Root->data,k);
	   
     
	 
	 
 }
 
 
 struct node *pruneUtil(struct node *root, int k, int *sum)
{
    // Base Case
    if (root == NULL)  return NULL;
 
    int lsum = *sum + (root->data);
    int rsum = lsum;
 
    root->left = pruneUtil(root->left, k, &lsum);
    root->right = pruneUtil(root->right, k, &rsum);
 
    *sum = max(lsum, rsum);
    
	
	if (*sum < k)
    {
        free(root);
        root = NULL;
    }
 
    return root;
}
 
struct node *prune(struct node *root, int k)
{
    int sum = 0;
    return pruneUtil(root, k, &sum);
} 	 
void SumGreaterthanK(struct node *Root)
{ 
   int k;
   k = 0; 
   Sum(Root,k,10);
}

int main()
{  
  struct node *Root = NewNode(4);
  Root->left = NewNode(2);
  Root->right = NewNode(5);
  Root->left->left = NewNode(1);
  Root->left->right = NewNode(3); 
  Root->right->left = NewNode(6);
  Root->right->right = NewNode(7);
  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  prune(Root,10);
 // SumGreaterthanK(Root);
// cout<<"\n"; LevelOrder(Root);
  LevelOrder(Root); 
 

  
    





return 0;
}

