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
	 
	 int SumCheck(struct node *Root)
	   {
	   	 if(Root==NULL)//|| Root->left==NULL && Root->right==NULL)
	   	 return 1;
		 else if(Root->left==NULL && Root->right==NULL)
		 return 1;
		 //else
		 
		 
		 int n1 = 0 , n2 =0  ;
		 if(Root->left!=NULL)
		 n1 = Root->left->data;
		 
		 if(Root->right!=NULL)
		 n2 = Root->right->data;
		 
		 if(Root->data== n1 + n2 && SumCheck(Root->left) && SumCheck(Root->right))
		  return 1;
		 
		 
		 return 0;
     	
		  	 
	   }
	   
	   void PrintPaths(struct node *Root, int *p ,int len);

void Root2Node(struct node *Root)
 {
 	 if(Root == NULL)
 	 return ;
 	 
 	 int paths[100];
 	 PrintPaths(Root,paths,0);
 }	   
void printarray(int *a,int len);
void PrintPaths(struct node *Root, int *p ,int len)
  {
  	    if(Root->left==NULL && Root->right ==NULL)
  	     {
  	     	 	   p[len++] = Root->data;
					printarray(p,len);
  	     }
  	     else if(Root!=NULL)
  	     {
  	     
		   p[len++] = Root->data;
  	       PrintPaths(Root->left,p,len);
  	       PrintPaths(Root->right,p,len);
  	     }
  	     else
  	     return ;
  	   
  }	  
  void printarray(int *a,int len)
   {
   	 F(i,0,len)
   	  cout<<a[i]<<" ";
   	  
   	  cout<<"\n";
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
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  
  cout<<" Sum Check "<<SumCheck(Root)<<"\n";
    Root2Node(Root); 
 




return 0;
}

