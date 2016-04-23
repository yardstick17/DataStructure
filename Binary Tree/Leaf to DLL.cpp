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
 struct node *LeafDLL(struct node *Root,struct node **start)
 {
 	
  if(Root==NULL)
 	 return NULL;
 	 
 	 if(Root->left==NULL && Root->right==NULL)
 	 {
 	    	    Root->right = *start;

		 if( *start != NULL)
 	    (*start)->left = Root;
 	    
 	    *start = Root;
 	 	return NULL;
 	 	 
 	 }
 	 
 	 Root->right  = LeafDLL(Root->right,start);
 	 Root->left = LeafDLL(Root->left,start);
 	 
	  return Root;
 	   
 }	/*
 
 struct node* LeafDLL(struct node *root, struct node **head_ref)
{
   // Base cases
   if (root == NULL)  return NULL;
 
   if (root->left == NULL && root->right == NULL)
   {
       // This node is going to be added to doubly linked list
       // of leaves, set right pointer of this node as previous
       // head of DLL. We don't need to set left pointer as left
       // is already NULL
       root->right = *head_ref;
 
       // Change left pointer of previous head
       if (*head_ref != NULL) (*head_ref)->left = root;
 
       // Change head of linked list
       *head_ref = root;
 
       return NULL;  // Return new root
   }
 
   // Recur for right and left subtrees
   root->right = LeafDLL(root->right, head_ref);
   root->left  = LeafDLL(root->left, head_ref);
 
   return root;
}
*/
 
 
 void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->right;
       
        
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
  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  struct node *start=NULL;
  LeafDLL(Root,&start);
  
  //LevelOrder(Root); 
  printList(start);

//    LevelOrder





return 0;
}

