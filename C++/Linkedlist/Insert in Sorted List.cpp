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
struct node
 {
 	 int data;
 	 struct node *next;
 };

void printlist(struct node *tmp)
{	 	int x ;
	  while(tmp != NULL)
	   { 
	      cout<< tmp->data <<" ";
	      tmp = tmp->next;
	   }
	   
}
void insertfront(struct node** start,int num)
{
	struct node* NewNode;
	NewNode = (struct node*)malloc(sizeof(struct node));
	
	NewNode->next = *start ;
	NewNode->data= num ;
	*start = NewNode ;
	
}
void InsertSorted(struct node **head,int num)
 {  
    struct node *NewNode;
     if( *head == NULL || num < (*head)->data)
	  {
	  	  NewNode = (struct node *)malloc(sizeof(struct node));
	  	  NewNode->data = num ;
	  	  NewNode->next = *head;
	  	  *head = NewNode;
	  }	 
	  else
	   { 
	     NewNode = *head;
	   	 while(NewNode->next != NULL && num > NewNode->next->data)
	   	  {    
	   	  	  NewNode = NewNode->next;
	   	  }
	   	  struct node *p;
			 p = (struct node *)malloc(sizeof(struct node));
	   	     p->data = num ;
			 p->next = NewNode->next;
			 NewNode->next = p; 
	   	  
	   }
 }


  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    
	insertfront(&start,101);
	insertfront(&start,80);
	insertfront(&start,78);
	insertfront(&start,61);
	insertfront(&start,55);
	insertfront(&start,45);
	insertfront(&start,40);
	InsertSorted(&start,5);
    cout<<"List is : \n";
	printlist(start);
	
 
return 0;
}


