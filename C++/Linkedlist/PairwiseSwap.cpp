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
void PairwiseSwap(struct node **head)
{
	 if(*head == NULL || (*head)->next == NULL)
	 return;
	 
	 struct node *prev = *head;
	 struct node *current = (*head)->next;
	 *head = current;
	 while(1)
	  {
	  	 struct node *tmp = current->next;
		   current->next = prev;
		   
		   if( tmp == NULL || tmp->next == NULL)
		     {
		     	  prev->next = tmp;
				   break; 
		     }
		     
		     prev->next = tmp->next;
		     
		     prev = tmp;
		     current = tmp->next;
	  	    
	  	     
	  }
	 
	 
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
  	insertfront(&start,12);
	PairwiseSwap(&start);
    cout<<"List is : \n";
	printlist(start);
	
 
return 0;
}


