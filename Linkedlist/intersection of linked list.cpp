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

struct node *Intersection(struct node *a,struct node *b)
 {
 	  struct node *result=NULL;
	  struct node **start;
 	  start = &result;
	  while(a != NULL && b != NULL)
	    {
	    	  if(a->data == b->data)
	    	    {
	    	    	 insertfront(start,a->data);
	    	    	 start = &(*start)->next;
	    	    	 a = a->next;
	    	    	 b = b->next;
	    	    	 
	    	    }
	    	    else if(a->data > b->data)
	    	      {
	    	      	 b = b->next; 
	    	      }
	    	      else
	    	      a = a->next;
	    	    
	    }
		return (result);   
 }

  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    struct node *start2 = NULL;
	insertfront(&start,700);
	insertfront(&start,680);
	insertfront(&start,514);
	insertfront(&start,410);
	insertfront(&start,360);
	insertfront(&start,280);
	insertfront(&start,101);
	
	insertfront(&start2,514);
	insertfront(&start2,410);
	insertfront(&start2,360);
	insertfront(&start2,180);
	insertfront(&start2,10);
	struct node *intersect=NULL;
	intersect = Intersection(start,start2);
	
    cout<<"First List is : \n";
	printlist(start);
	cout<<"\nSecond List is :\n";
	printlist(start2);
    cout<<"\nIntersected List is :\n";
	printlist(intersect); 
return 0;
}


