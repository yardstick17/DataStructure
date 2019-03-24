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
void RemoveCycle(struct node *LoopNode,struct node *head);

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

bool DetectAndRemove(struct node *head)
{
	  struct node *slow,*fast;
	  slow = head; fast = head ;
	  while(slow  && fast && fast->next)
	    {
	    	 slow = slow->next;
	    	 fast = fast->next->next;
	    	 if(slow==fast)
	    	   {
	    	   	    cout<<"Yes Cycle Found"<<"\n";
					RemoveCycle(slow,head);
					return true ;

	    	   	    
	    	   }
	    }
	    return false;
	    
}

void RemoveCycle(struct node *LoopNode,struct node *head)
 {
 	 struct node *ptr1,*ptr2;
 	 ptr1 = head ;
	 ptr2 = LoopNode;
	 while(1) 
	 {    
	      ptr2 = LoopNode;
	 	  while(ptr2->next != LoopNode && ptr2->next !=ptr1 )
	 	    {
	 	    	   ptr2= ptr2->next;
	 	    	   
	 	    }
	 	    if(ptr2->next == ptr1 )
	 	     {
	 	     	break;
	 	     }
	 	    else
			  {
			  	 ptr1 = ptr1->next;
			  } 
	 }
	 ptr2->next = NULL; 
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
	start->next->next->next->next->next->next->next = start->next->next;
    bool check = DetectAndRemove(start);
	cout<<"List is : \n";
    printlist(start);
	
	
 
return 0;
}


