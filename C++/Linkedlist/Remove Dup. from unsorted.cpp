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

 void RemoveDup(struct node *head)
  {
  	  struct node *ptr1,*ptr2,*prev;
  	  ptr1 = head ;
  	  ptr2 = head;
  	  while(ptr1!=NULL && ptr1->next !=NULL)
  	    {    
  	     
  	    	 ptr2 = ptr1;
  	    	   while(ptr2->next != NULL)
  	    	     {     
  	    	     	  if(ptr1->data == ptr2->next->data)
  	    	     	   {   
                         prev = ptr2->next;
  	    	     	   	 ptr2->next = ptr2->next->next;
  	    	     	   	 free(prev);
  	    	     	   }
  	    	     	   else
  	    	     	   {
  	    	     	   	  ptr2 = ptr2->next;
  	    	     	   }
  	    	     }
  	    	     ptr1 = ptr1->next;
  	    }
  }

  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    
	insertfront(&start,7);
	insertfront(&start,7);
	
	insertfront(&start,7);
	insertfront(&start,7);
	insertfront(&start,7);

	RemoveDup(start);
    cout<<"List is : \n";
	printlist(start);
	
 
return 0;
}


