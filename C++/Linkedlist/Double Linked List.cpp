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
		 struct node *prev;
        };
	
	
 void insertfront(struct node **head,int num)
	{
	   struct node *NewNode;
	   NewNode = (struct node *)malloc(sizeof(struct node));
	   NewNode->data = num ;
	   NewNode->next = *head;
	   NewNode->prev = NULL;
	   if(*head!= NULL)
	     {
	     	  (*head)->prev = NewNode;
	     }
	     *head = NewNode;
	   	  
	}
	
	void DeleteNode(struct node **head,int num)
	 {
	 	 struct node *current = *head;
	 	 if(current == NULL)
	 	  return ;
	 	  while(current!= NULL && current->data!=num)
	 	    {
	 	    	 current= current->next;
	 	    }
            if(current == *head)
             {
             	 *head= (*head)->next;
             }
			if(current->next!= NULL)
              {
              	 current->next->prev = current->prev;
              }
              
              if(current->prev!=NULL)
                {
                	 current->prev->next = current->next;
                }
                free(current);
	 }

 void printlist(struct node *head)
	 {   struct node *current = head,*previous = NULL;
	 	 while(current!=NULL)
	 	  {
	 	  	 cout<<current->data<<" ";
	 	  	  previous = current;
	 	  	 current = current->next;
	 	  }
	 	  cout<<"\nPrintint in Reverze:\n";
	 	  while(previous!=NULL)
	 	   {
	 	   	   cout<<previous->data<<" ";
	 	   	   previous = previous->prev;
	 	   }
	 }


int main()
{
    struct node *start = NULL;
  	insertfront(&start,5);
  	insertfront(&start,4);
    insertfront(&start,54);
    insertfront(&start,51);
      DeleteNode(&start,5);

   //push(&start,5);push(&start,5);push(&start,5);push(&start,5);
  printlist(start);
return 0;
}

