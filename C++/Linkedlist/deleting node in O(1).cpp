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
	      cout<< tmp->data <<" \n";
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



  
  void insertafter2(struct node *after,int num)
 {
 	 struct node *tmp;
 	 tmp->data = num;
 	 tmp->next = after->next;
 	 after->next = tmp;
 	 
 } 

 void insertlast(struct node **start,int num)
  {
  	  struct node *tmp, *NewNode ;
  	  NewNode = (struct node *)malloc(sizeof(struct node));
  	  NewNode->data = num ; 
  	  tmp = *start;
  	  while(tmp->next!=NULL)
  	   {
  	   	   tmp = tmp->next ;
  	   }
  	   tmp->next = NewNode;
  	   NewNode->next = NULL; 
  	   
  	   
  }
  
  
  void nthelementfromlast(struct node *head,int n)
   {
   	  int static i = 0 ;
   	  if(head == NULL)
   	  return;
		
		nthelementfromlast(head->next,n);
		if(++i==n)
		cout<<head->data<<" <-- here it is, nth last elemnt  \n";  
   }
   
   void DeleteNode(struct node *node)
    {
    	  struct node *tmp=node->next ;
    	  node->data = tmp->data;
		  node->next = tmp->next;
		  free(tmp); 
    }
int main()
{
    int t;
    struct node *start =NULL;
    struct node *second=NULL;
    struct node *third =NULL;
    start  = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
    third  = (struct node *)malloc(sizeof(struct node));
    start->next= second;
    start->data=5;

    second->next = third;
	second->data=10;
	
	third->data= 14;
	third->next=NULL;
	insertfront(&start,7);
		insertfront(&start,8);
	insertfront(&start,14);
	insertfront(&start,41);
	insertfront(&start,6);
	insertfront(&start,8);
	insertfront(&start,1);



    nthelementfromlast(start,5);
	printlist(start);
	DeleteNode(start);//head); 
    cout<<" After Deletion of Node: List is : \n";
	printlist(start);
 
return 0;
}


