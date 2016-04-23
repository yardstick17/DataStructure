
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
struct node *fixNxtPtr(struct node *Root);

void fixPrevPtr(struct node *Root)
 {    static struct node *Prev = NULL;
 	 if(Root)
 	 {
 	 	 fixPrevPtr(Root->left);
 	 	 Root->left = Prev;
 	 	 Prev = Root;
 	 	 fixPrevPtr(Root->right);
     }
 }	 

struct node *fixNxtPtr(struct node *Root)
  {
  	 while(Root && Root->right!=NULL)
  	 	Root = Root->right;
    struct node *nxt = NULL;
  	 while(Root && Root->left!=NULL)
  	 {
  	 	 nxt = Root;//->right= nxt;

  	 	 Root = Root->left;
  	 	 Root->right = nxt;

      }
      return Root;
  }


struct node *BTtoDLL(struct node *Root)
{
	 fixPrevPtr(Root);
	 return fixNxtPtr(Root);
}	


void printList(struct node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->right;
    }
}
/*struct node *fixNextPtr(struct node *root)
{
    struct node *prev = NULL;
 
    // Find the right most node in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;
 
    // Start from the rightmost node, traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
 
    // The leftmost node is head of linked list, return it
    return (root);
}
 */
int main()
{
  struct node *Root = NewNode(1);
 
  Root->left = NewNode(2);
  Root->right = NewNode(3);
  Root->left->left = NewNode(4);
  Root->left->right = NewNode(5); 
 // Root->right->left = NewNode(6);
  Root->right->right = NewNode(6);
  Inorder(Root);
  cout<<"\n";
 struct node *Rot = BTtoDLL(Root);
 printf("DLL Traversal: ");
    printList(Rot);

    





return 0;
}

