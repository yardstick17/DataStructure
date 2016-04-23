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

void InsertFront(struct Lnode **head,int data)
 {
 	  struct Lnode *New = (struct Lnode *)malloc(sizeof(struct Lnode));
 	  New->data = data;
 	  New->next = *head;
 	  *head = New;
 }
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

struct Lnode *Middle(struct Lnode *head)
 {
 	 struct Lnode *slow,*fast;
 	 slow = fast = head;
 	 while(slow->next && fast->next)
 	  {
 	  	 slow = slow->next;
 	  	 fast = fast->next->next;
 	  }
 	  return slow;
 }
int FillArray(int *a,struct Lnode *head)
{
	 if(head == NULL)
	  return 0 ;
	  int i = 0 ;
	  while(head!=NULL)
	  {
	  	  a[i] = head->data;
	  	  cout<<a[i]<<" ";
	  	  i++;
	  	  head  = head->next ;
	  }
	  return i;
	  
}
struct node *Util(int *a,int low,int high)
 {
 	 if(high>low)
 	 {
 	 
	 struct node *Root = (struct node *)malloc(sizeof(struct node ));
	 int mid = (low + high)/2; 
	 Root->data = a[mid];
	 
	 Root->left =  Util(a,low,mid);
	 Root->right = Util(a,mid+1,high);
	 
	 return Root;
	}
	return NULL;
}
 
struct node *ConverList2BST1(struct node *Root,struct Lnode **head)
{ 
    int a[100],b[1000];
	int n = FillArray(a,*head);
	F(i,0,n)
	  {
	  	 b[i] = a[n-1 -i];
	  }
	return Util(b,0,n);
}
int Count(struct Lnode *head)
 {
 	 if(head == NULL)
 	 return 0 ;
 	 int i = 0 ;
 	 struct Lnode *tmp = head;
 	 while(tmp!=NULL)
 	  {
 	  	 i++;
 	  	 tmp = tmp->next;
 	  }
 	  return i ;
 }
 
 struct node *Util2(struct Lnode **head,int n)
  {
  	 if(n<=0)
  	 return NULL;
  	 
  	 
  	 struct node *left = Util2(head,n/2);
	 struct node *Root = NewNode((*head)->data);
	 Root->left = left;
	 (*head) = (*head)->next;
	 Root->right = Util2(head, n - n/2 - 1 );
	 return Root; 
	    
  }
struct node *ConverList2BST2(struct node *Root,struct Lnode **head)
{
	 int n = Count(*head);
	 return Util2(head,n);
}
int main()
{
  
   
 struct Lnode *head = NULL;
 InsertFront(&head,4);
 InsertFront(&head,14);
 InsertFront(&head,24);
 InsertFront(&head,41);
 InsertFront(&head,46);
 /*struct node *Root = ConverList2BST1(Root,&head);
 cout<<"\n";
 inorder(Root);*/

  
 struct node *Root = ConverList2BST2(Root,&head);
 cout<<"\n";
 inorder(Root);

   





return 0;
}

