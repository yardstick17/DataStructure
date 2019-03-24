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
	 
struct node *nextRyt(struct node *Root,int k)
{
	 if(Root==NULL)
	 return NULL;
	 
	 queue<struct node *>Q;
	 Q.push(Root);
	 struct node *tmp,*prev;
	 int flag = 1;
	 while(1&&flag)
	  {
	  	 int count = Q.size();
	  	 if(Q.empty())
	  	 break;
	  	 while(count)
	  	 {  int e = Q.front()->data;
	  	 	 if(e==k && count!=1)
	  	 	 {
	  	 	 	tmp = Q.front();
	  	 	    Q.pop();
	  	 	
	  	 	   
	  	 	 //prev = tmp;
	  	 	 cout<<tmp->data<<" ";
	  	 	 if(tmp->left!=NULL)
	  	 	  Q.push(tmp->left);
	  	 	 
			if(tmp->right!=NULL)
			Q.push(tmp->right);
			cout<<"Next Ryt is : "<<Q.front()->data<<" ";
			flag = 0 ;
			break;
			
	  	 	 	
	  	 	 }
	  	 	 
	  	 	 
			 tmp = Q.front();
	  	 	 Q.pop();
	  	 	
	  	 	   
	  	 	// prev = tmp;
	  	 	// cout<<tmp->data<<" ";
	  	 	 if(tmp->left!=NULL)
	  	 	  Q.push(tmp->left);
	  	 	 
			if(tmp->right!=NULL)
			Q.push(tmp->right);
			
			count--; 
	  	 	  
	  	  }
	  	  //cout<<"\n";
	  }
	  if(flag == 1)
	  cout<<"NULL";
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
  //if(nextRyt(Root,3) != NULL)
   nextRyt(Root,1);//->data<<endl
  //else
 // cout<<"NULL!";
  
    





return 0;
}

