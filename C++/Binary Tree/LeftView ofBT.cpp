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
 
  int Height(struct node *Root);

/*int Height(struct node *Root)
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
  */
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
int Calc(struct node *Root,int Level)
 {  static int max = 0 ;
 	 
	 if(Root == NULL)
 	 return max;
	  if(Level % 2 != 0)
 	 {
 	 	 if(max<Level)
 	 	 max = Level;
 	 }
 	
 	 
 	 Calc(Root->left,Level+1);
 	 Calc(Root->right,Level +1);
 	  
 }	 
 int Height(struct node *Root)
  {
  	 if(Root==NULL)
  	 return 0;
  	 
  	 return  1 + max(Height(Root->left), Height(Root->right));
  }
int DeepOdd(struct node *Root)
{  
   int height = Height(Root);
   return Calc(Root,1);
 }
void LeftView(struct node *Root)
{
	 struct node *tmp = NULL;
	 queue< struct node*>Q;
	 Q.push(Root);
	int flag = 0 ;
while(1)
	{
		  int count = Q.size();
		  if(Q.empty())
		  break;	
		   flag = 0 ;
		while(count>0)
	  	   {
	  	   	 tmp = Q.front();
			 Q.pop();
			 if(flag==0)
			 {
			   flag = 1 ;
			  cout<<tmp->data<<" ";
		     }
			 if(tmp->left!=NULL)
			    Q.push(tmp->left);
			  
			 if(tmp->right!=NULL)
			    Q.push(tmp->right);
			    
			    count--;
		 }
	  	   cout<<"\n";
	  }
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
  Root->right->right->left = NewNode(17);

 Root->right->right->left->right = NewNode(147);
 Root->right->right->left->right->left = NewNode(14);
 
  LevelOrder(Root); 
  cout<<"\n";
  /* Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";*/
  //cout<<" Height at odd level is : " <<DeepOdd(Root);
  LeftView(Root);
   
  
    





return 0;
}


