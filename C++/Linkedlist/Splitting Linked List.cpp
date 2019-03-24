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
#include<assert.h>
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
void MoveNode(struct node **destination,struct node **source);

void SplittingList(struct node *head,struct node **a,struct node **b)
{
	  struct node *current = head;
	  struct node *alist = NULL;
	  struct node *blist = NULL;
	  while(current != NULL)
	  {
	  	 MoveNode(&alist,&current);
	  	 if(current!= NULL)
	  	  {
	  	  	  MoveNode(&blist,&current);
	  	  }
	  	   
	  }
	  *a = alist;
	  *b = blist;
	  
}
void MoveNode(struct node **destination,struct node **source)
{
	 struct node *NewNode = *source;
	 assert(NewNode!= NULL);
	  
	  *source = (*source)->next;
	 NewNode->next = *destination;
	 *destination = NewNode;
	   
	  
}


  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    struct node *a = NULL;
    struct node *b = NULL;
    
    
	insertfront(&start,7);
	insertfront(&start,8);
	insertfront(&start,14);
	insertfront(&start,41);
	insertfront(&start,6);
	insertfront(&start,8);
	insertfront(&start,1);
	
    cout<<"List is : \n";
	printlist(start);
	SplittingList(start,&a,&b);
	
	cout<<" After Splitting List is : \nA:";
	printlist(a);
	cout<<"\nB:";
	printlist(b);
 
return 0;
}


