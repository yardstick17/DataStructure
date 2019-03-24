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
bool Balance(struct node *Root,int *h)
{
	 if(Root==NULL)
	 return true; 
	 
	 int lh = *h + 1 ;
	 int rh = lh;//*h + 1;
	 
	 bool b = Balance(Root->left,&lh);
	 bool b2 = Balance(Root->right,&rh);
	 cout<<lh<<" "<<rh<<" and h: " <<*h<<"\n";
	 *h = max(lh,rh);
	 
	 int x = lh - rh ;
	
	 if(x<0)
	 x = -x;
	 
	 if(x<=1)
	 return 1&b&b2;
	 else
	 return false;
}
bool isBalance(struct node *Root)
 {
 	 if(Root==NULL)
 	 return 1;
 	 int h=0;
	  
 	return Balance(Root,&h);
 	 
 	 
 }	 

int main()
{  
  struct node *Root = NewNode(4);
  Root->left = NewNode(2);
  Root->right = NewNode(5);
  Root->left->left = NewNode(1);
  Root->right->right = NewNode(6);
 /* Root->right->right->right = NewNode(7);
  Root->left->left->left = NewNode(8);
  Root->left->left->left->left = NewNode(7);
 // Root->right->right->right->left = NewNode(7);
*/
  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  cout<<isBalance(Root);
  
    





return 0;
}

