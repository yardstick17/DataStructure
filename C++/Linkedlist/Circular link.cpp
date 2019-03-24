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
	  struct node *next;
};
  void insertfront(struct node **head,int num)
   {
   	   struct node *NewNode;
   	   struct node *current = *head;
   	   NewNode = (struct node *)malloc(sizeof(struct node));
   	   NewNode->data = num ;
   	   NewNode->next = *head;
   	   if(*head !=NULL)
   	    {
   	    	  while(current->next!= *head)
   	    	    {
   	    	    	 current = current->next;
   	    	    }
   	    	    current->next = NewNode; 
   	    }
   	    else
   	    NewNode->next = NewNode;
   	    
   	    *head = NewNode;
   }

void printlist(struct node *head)
 {   struct node *current = head;
 	 if(head!=NULL)
 	    {
 	    	do {
 	    	 
 	    	 cout<<current->data<<" ";
 	         current = current->next;
			  } 	    	 while(current!= head );

		 }
 	    
 }
int main()
{
   struct node *start = NULL;
   insertfront(&start,5);
   insertfront(&start,6);
   insertfront(&start,10);
   
   printlist(start);
   





return 0;
}

