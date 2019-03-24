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
struct Lnode{
	 int data;
	 struct Lnode *next;
};


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
	 
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


 

int Count(struct node *head)
 {
 	 if(head == NULL)
 	 return 0 ;
 	 int i = 0 ;
 	 struct node *tmp = head;
 	 while(tmp!=NULL)
 	  {
 	  	 i++;
 	  	 tmp = tmp->right;
 	  }
 	  return i ;
 }
 
 struct node *Util2(struct node **head,int n)
  {
  	 if(n<=0)
  	 return NULL;
  	 
  	 
  	 struct node *left = Util2(head,n/2);
	 struct node *Root = *head;//NewNode((*head)->data);
	 (*head)->left = left;
	  (*head) = (*head)->right;///Root = (Root)->right;
	 (Root)->right = Util2((head), n - n/2 - 1 );
	 return Root; 
	    
  }
struct node *ConverList2BST2(struct node **Root)//,struct Lnode **head)
{
	 int n = Count(*Root);
	 return Util2(Root,n);
}

void insertfront(struct node **head,int num)
	{
	   struct node *NewNode;
	   NewNode = (struct node *)malloc(sizeof(struct node));
	   NewNode->data = num ;
	   NewNode->right = *head;
	   NewNode->left = NULL;
	   if(*head!= NULL)
	     {
	     	  (*head)->left = NewNode;
	     }
	     *head = NewNode;
	   	  
	}


void printList(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}
 
	
int main()
{
  
   
 struct node *Root =NULL;
 insertfront(&Root,255); //insertfront(&Root,255);
 insertfront(&Root,251);
 insertfront(&Root,241);
 insertfront(&Root,25);
 insertfront(&Root,5);
 insertfront(&Root,2);

  
 printList(Root);

  
 struct node *tmp =  ConverList2BST2(&Root);//,&head);
 cout<<"\n";
 inorder(tmp);

   





return 0;
}

