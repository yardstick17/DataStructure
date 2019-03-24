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
struct node *LCA(struct node *Root,int n1,int n2,int *p)
{
	 if(Root==NULL)
	 return NULL;
	 
	 if(Root->data==n1 || Root->data == n2)
	 {
	 
	 return Root;
     *p = 0;
	 }
	 
	 struct node *leftLCA = LCA(Root->left,n1,n2,p);
	 struct node *RightLCA = LCA(Root->right,n1,n2,p);
	 
	 
	 if(leftLCA && RightLCA)
	 return Root;
	 
	 if(leftLCA!=NULL)
	 {
	 *p = 0;
	 return leftLCA;
	 }
	 else
	 {
	  *p = 1 ;
	 return RightLCA;
}
}


int getLevel(struct node *Root,int k)
{
	 if(Root==NULL)
	 return 0;
	 
	 queue<struct node *>Q;
	 Q.push(Root);
	 struct node *tmp,*prev;
	 int Level = 0 ;
	 while(1)
	  {
	  	 int count = Q.size();
	  	 Level++;
	  	 if(Q.empty())
	  	 break;
	  	 while(count)
	  	 {  
			 tmp = Q.front();
	  	 	 Q.pop();
	  	 	 if(k == tmp->data)
	  	 	 return Level;
	  	 	 
		  	 	 if(tmp->left!=NULL)
		  	 	  Q.push(tmp->left);
	  	 	 
				if(tmp->right!=NULL)
				Q.push(tmp->right);
				
			count--; 
	  	 	  
	  	  }
	  	  
	  }
	 
}	
int LCAdistance(struct node *Root,int n1,int n2)
{
	 int p;
	 p = 0 ;
     struct node*tmp = LCA(Root,n1,n2,&p); 
     int L1 = getLevel(Root,n1);
     int L2 = getLevel(Root,n2);
     int L3  = getLevel(Root,tmp->data);
     if(p==0)
     return (L2-L1)>0?L2-L1:L1-L2;
     else
     return L2 + L1 - 2*L3;//>0?L2-L1:L1L2;
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
  cout<<LCAdistance(Root,1,4);//->data;
    





return 0;
}

