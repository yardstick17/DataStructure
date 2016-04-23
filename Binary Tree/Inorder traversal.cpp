			/* AK_47*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<stack>
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
	 
	 int SumCheck(struct node *Root)
	   {
	   	 if(Root==NULL)
	   	 return 1;
		 else if(Root->left==NULL && Root->right==NULL)
		 return 1;
		 
		 
		 int n1 = 0 , n2 =0  ;
		 if(Root->left!=NULL)
		 n1 = Root->left->data;
		 
		 if(Root->right!=NULL)
		 n2 = Root->right->data;
		 
		 if(Root->data== n1 + n2 && SumCheck(Root->left) && SumCheck(Root->right))
		  return 1;
		 
		 
		 return 0;
     	
		  	 
	   }
	   
	   void InorderTraversal(struct node *Root)
	     {
	     	 stack<struct node *> s;
	     	 
	     	  bool b = 0 ;
	     	  while(!b)
	     	    {
	     	    	  
					  if(Root!=NULL)
					   {
					      s.push(Root);
	     	    	      Root = Root->left;
	     	           }
	     	           
	     	           else
						{
						  if(!s.empty())
	     	               {
	     	                   struct node *tmp = s.top();
	     	                   s.pop();
							   Root = tmp->right;
							   cout<<tmp->data<<" "; 	 
	     	               }
	     	               else
	     	               b = 1 ;
	     	    	  
	     	    	  
	     	    	  
	     	    }
	     }
	 }
	   
	   
int main()
{
  struct node *Root = NewNode(14);
 
  Root->left = NewNode(5);
  Root->right = NewNode(9);
  Root->left->left = NewNode(2);
  Root->left->right = NewNode(3); 
  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\nInoder Trversal using stack : ";
  InorderTraversal(Root);
  
  





return 0;
}

