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
	struct node *left,*right;
	 
};

struct node *NewNode(int item)
{
	 struct node *tmp = (struct node *)malloc(sizeof(struct node));
	 tmp->data  = item;
	 tmp->left = tmp->right = NULL;
	 return tmp;
	 
	 
}
struct node  *Insert(struct node *Root,int item)
{
	 if(Root==NULL)
	 return NewNode(item);
	 
	 if(Root->data>item)
	 Root->left = Insert(Root->left,item);
	 else if(item > Root->data)
	 Root->right  = Insert(Root->right,item);
   return Root;
}
	 
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *findInorder(struct node *Root)
{
	struct node *tmp = Root;
	 while(tmp->left!=NULL)
	  {
	  	 tmp = tmp->left;
	  }
	  return tmp;
} 



struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = findInorder(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}





struct node *DeleteKey(struct node *Root,int key)
{
	 if(Root==NULL)
	 return Root;
	 
	 if(key < Root->data)
	 Root->left = DeleteKey(Root->left,key);
	 
	 else if(key > Root->data)
	 Root->right = DeleteKey(Root->right,key);
	
	else {
	        
			
			if(Root->left == NULL)
	 	      {
	 	      	   struct node *tmp = Root->right;
	 	      	   free(Root);
	 	      	   return tmp;
	 	      }
	 	      else if(Root->right == NULL)
	 	        {
	 	        	  struct node *tmp = Root->left;
	 	        	  free(Root);
	 	        	  return tmp;
	 	        }
	 	        
	 	        struct node *tmp = findInorder(Root->right);
	 	        Root->data = tmp->data;
	 	        Root->right = DeleteKey(Root,tmp->data);
	 	        
         }
         return Root;
}
 
int main()
{
   struct node *Root = NewNode(50);
   Insert(Root,41);
   Insert(Root,9);
   Insert(Root,83);
   Insert(Root,90);
   Insert(Root,144);
   Insert(Root,8);
   
   inorder(Root);
   cout<<"\n";
   DeleteKey(Root,83);
   DeleteKey(Root,9);
 
   inorder(Root);   
   
   





return 0;
}

