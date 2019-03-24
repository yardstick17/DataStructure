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

void MiddleElement(struct node *head)
 { 
    struct node *slow,*fast;
		slow = head ;
		fast = head;
		while(fast!=NULL && fast->next!=NULL)
		  {
		  	  slow = slow->next;
		  	  fast = fast->next->next;
		  } 
		  cout<<"Slow Element Refers to Middle of the List:"<<slow->data<<endl;
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
	insertfront(&start,0);
    cout<<"List is : \n";
	printlist(start);
	MiddleElement(start);//head);
	
 
return 0;
}


