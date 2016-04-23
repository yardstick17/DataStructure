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
 struct node *ReverseList(struct node *head)//,int num,)
  {  
    struct node *prev=NULL;
	struct node *next=NULL;
  	
  	 struct node *current = head;
  	
  	 int count = 0 ; 
  	 while(current!= NULL&& count<3)
  	  {
  	  	next = current->next;
  	  	current->next = prev ; 
  	  	prev = current;
  	  	count++;
  	  	current = next ;
  	  }
  	  if(current != NULL)
  	  {
  	  	head->next = ReverseList(next);
  	  	
  	  }
  	  return prev;
    
  	 
  	  
  }


  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    
	insertfront(&start,7);
	insertfront(&start,8);
	insertfront(&start,14);
	insertfront(&start,41);
	insertfront(&start,6);
	insertfront(&start,8);
	insertfront(&start,1);
	 struct node *prev = NULL;
  	 struct node *next = NULL;
    cout<<"List is : \n";
	printlist(start);
	start = ReverseList(start);//,3,prev,next);
	cout<<"\nAfterRiversing the list\n";
	printlist(start);
	
 
return 0;
}


