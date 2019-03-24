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
void ReverseUtil(struct node *Root,int a[],int Level,int *index,int code)
 {
 	 if(Root==NULL)
	  return ;
	  
	  ReverseUtil(Root->left,a,Level+1,index,code);
 	   if(Level%2!=0)
 	    {   if(code)
 	         a[(*index)++] = Root->data;
 	         else
			  Root->data = a[(*index)++];   
 	     }
 	  ReverseUtil(Root->right,a,Level+1,index,code);
 	  
 	 
 }	
 
void reverse(int arr[], int n)
{
    int l = 0, r = n-1;
    while (l < r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++; r--;
    }
} 
void ReverseOddLevel(struct node *Root)
 {   int a[100];
     int index = 0 ;
 	 ReverseUtil(Root,a,0,&index,1);
 	 reverse(a,index);
 	 index = 0 ;
 	 ReverseUtil(Root,a,0,&index,0);
 	 
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
  Root->right->right->left = NewNode(14);
  Root->right->left->right = NewNode(74);

  LevelOrder(Root); 
  cout<<"\n";
 
  ReverseOddLevel(Root);
  LevelOrder(Root); 
  cout<<"\n";
 
return 0;
}

