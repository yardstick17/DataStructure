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
void Mirror(struct node *Root)
 {
 	 if(Root==NULL)
 	 return;
 	 
 	 Mirror(Root->left);
 	 Mirror(Root->right);
 	 
 	 struct node *tmp;
 	 tmp = Root->left;
 	 tmp= Root->right;
 	 Root->right = Root->left;
	 Root->left= tmp;//Root->rigt;
	   
 }	 
bool isStructureSame(struct node *Left, struct node *Right)
 {
 	 if(Left==NULL && Right == NULL)
 	 return true;
 	 else if(Left!=NULL && Right!=NULL)
 	 {
 	 	isStructureSame(Left->left,Right->left);
 	 	isStructureSame(Left->right,Right->right);
 	 }
 	 else
 	 return false;
 } 
bool FoldedBT(struct node *Root)
 {
 	 struct node *Left = Root->left;
 	 Mirror(Left);
 	 bool b =  isStructureSame(Root->left,Root->right);
 	 Mirror(Left);
  return b ;
 }	 
 
int getLevel(struct node *Root,int ta,int level)
 {
 	 int h;
	 if(Root==NULL)
	   return -1;
	 else if(Root->data == ta)
 	   return level;
 	 else
 	  {    h = getLevel(Root->left,ta,level+1);
 	  	   if(h!= -1)
 	  	      return h;
		   h = getLevel(Root->right,ta,level+1); 
		   if(h!= -1)
 	  	      return h;	
		    
 	  }
 	  
 	 
 } 
int getlevel(struct node *Root,int data)
{
	 
	 return getLevel(Root,data,1);//if(Root->data == data)
	 
	 
}

int main()
{
  struct node *Root = NewNode(14);
 
  Root->left = NewNode(5);
  Root->right = NewNode(9);
  Root->left->left = NewNode(21);
  Root->right->right = NewNode(3); 
  Root->left->left->left = NewNode(2);
  Root->left->left->left->left = NewNode(74);

  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  
cout<<"isFolded:"<<FoldedBT(Root)<<endl;
    
cout<<endl;
Postorder(Root);
cout<<"\n"<<getlevel(Root,2)<<"\n";






return 0;
}

