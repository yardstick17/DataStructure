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
void deletenode(struct node **start,int num)
 {
 	struct node *tmp,*prev ;
 	tmp  = *start ;
 	prev = *start;
 	if(tmp->data==num)
 	  {
 	  	  *start = tmp->next ;
 	  	  free(start);
 	  	  return; 
 	  }
 	  
	 while(tmp->data != num && tmp->next!=NULL)
 	  {  
	     prev = tmp;
 	  	 tmp = tmp->next;
 	  }
 	  if(tmp->next==NULL)
 	    {
 	    	 prev->next = NULL;
 	    	 free(tmp);
			  return;
 	    }
 	 prev->next = tmp->next ;
 	 free(tmp);
 	 
 }

void printlist(struct node *tmp)
{	 	int x ;
	  while(tmp != NULL)
	   { 
	      cout<< tmp->data <<" \n";
	      tmp = tmp->next;
	   }
	   
}
int main()
{
    struct node *start =NULL;
    struct node *second=NULL;
    struct node *third =NULL;
    start  = (struct node *)malloc(sizeof(struct node));
	second = (struct node *)malloc(sizeof(struct node));
    third  = (struct node *)malloc(sizeof(struct node));
    start->next= second;
    start->data=51;

    second->next = third;
	second->data=120;
	
	third->data= 14;
	third->next=NULL;
	printlist(start);

	deletenode(&start,14);
	
	cout<<"After Deletion List is : \n";
	printlist(start);
		




return 0;
}

