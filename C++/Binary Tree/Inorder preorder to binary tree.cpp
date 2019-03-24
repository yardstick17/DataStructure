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
	 char data;
	 struct node *left;
	 struct node *right;
};

struct node *NewNode(char data)
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
	   
int search(char in[],int instart,int inEnd,char c)
 {   int i = 0;
 	 for( i = instart; i< inEnd ;i++)
 	   {
 	   	 if(in[i]==c)
 	   	 {
 	   	 	 break;
 	   	 }
 	   }
 	   return i;
 }
struct node *buildTree(char in[],char pre[],int inStart,int inEnd)
 {
 	  static int preIndex = 0 ;
 	  if(inStart  > inEnd )
 	     return NULL;
 	   struct node *tNode = NewNode(pre[preIndex++]);
 	   
	 if(inStart == inEnd)
 	   return tNode;
 	 
	  int inIndex = search(in,inStart,inEnd,tNode->data);
	  
	  tNode->left = buildTree(in,pre,inStart,inIndex-1);
	  tNode->right = buildTree(in,pre,inIndex+1,inEnd);
	  
	  return tNode;
	  
	    
 	   
 	   
 	   
 }	   

int main()
{ 
   static int preindex = 0 ;
   //if(inSt)
  
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  //cout<<" Sum Check "<<SumCheck(Root);
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, pre, 0, len - 1);

  printf("\n Inorder traversal of the constructed tree is \n");
  Inorder(root);



return 0;
}

