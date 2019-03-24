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
void SumUtil(struct node *Root,int curr_sum , int *max_sum,struct node **Leaf)
 {
 	 if(Root==NULL)
 	 return ;
 	 curr_sum = curr_sum + Root->data;
 	 if(Root->left==NULL && Root->right==NULL)
 	  {
 	  	 if(curr_sum > *max_sum)
 	  	  {
 	  	  	 *max_sum = curr_sum;
 	  	  	  *Leaf = Root;
 	  	  }
 	  	  return;
 	  }
 	  SumUtil(Root->left,curr_sum,max_sum,Leaf);
 	  SumUtil(Root->right,curr_sum,max_sum,Leaf);

 	  
 }	 
 
void FindPath(struct node *Root, struct node *target,int path[],int level,int a[])
 {
 	 if(Root==NULL)
 	 return;// 0;
 	 
 	 path[level] = Root->data;
 	 if(target == Root)
 	 {   
 	     F(i,0,level+1)
 	     cout<<path[i]<<" ";
 	     
 	 	 return;
 	 }
 	 FindPath(Root->left,target,path,level+1,a);
 	 FindPath(Root->right,target,path,level+1,a);
 }	 
struct node *Leafnode(struct node *Root)
 {
 	 int max_sum = -5 ;
 	 struct node *leaf=NULL;
 	 SumUtil(Root,0,&max_sum,&leaf);
 	 int path[100];
 	 int a[100];
	 
	 FindPath(Root,leaf,path,0,a);// = strlen(path);
 	 
	 
 	 
	  return leaf;
 }
int main()
{  
  struct node *Root = NewNode(4);
  Root->left = NewNode(12);
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
  cout<<Leafnode(Root)->data<<" \n";



return 0;
}

