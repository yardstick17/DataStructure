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
#include<climits>
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

void MergeList(struct node **a,struct node **b,struct node **result)
{
	  
	  struct node *alist = *a;
	  struct node *blist = *b;
	  struct node *List = NULL;
	  while(1)
	   {
	   	    if(alist == NULL)
		   	    {
		   	          while(blist!= NULL)
		   	          {
		   	          	 MoveNode(&List,&blist);
		   	          }
		   	          break;
		   	     }
			else if(blist == NULL)
	   	         {
		   	           while(alist!=NULL)
						{
							MoveNode(&List,&alist);
						}
						 
		   	          break;
				 }   
				else if(alist->data > blist->data )
	   	       {
	   	       	     MoveNode(&List,&blist);
	   	       }
	   	       else
	   	        {
	   	        	 MoveNode(&List,&alist);
	   	        }
	   	        
	   }
	   	   	    *result = List ;    

}
void MoveNode(struct node **destination,struct node **source)
 {
 	  struct node *NewNode = *source;
 	  assert(NewNode!= NULL);
 	  *source = (*source)->next;
 	  NewNode->next = *destination;
 	  *destination = NewNode;

}
struct node *Merge(struct node *l1,struct node *l2)
{
    struct node *list1 , *list2 ;
   list1 = l1 , list2 = l2 ;
        int n1 , n2 ;
        struct node *New = NULL;
        while(list1 != NULL || list2 != NULL)
         {
              n1 = 0 , n2 = 0 ;
              if(list1)
              n1= list1->data;
              else
              n1 = INT_MAX;
              if(list2)
              n2 = list2->data;
              else
              n2 = INT_MAX;
              
              if(n1 < n2)
               {
                    MoveNode(&New , &list1);
               }
               else
               {
                    MoveNode(&New , &list2);
               }
       }
       return New;
}
  
  
int main()
{
    int t;
    struct node *start =NULL;
    struct node *start2 = NULL;
    struct node *List = NULL; 
	insertfront(&start,87);
	insertfront(&start,84);
	insertfront(&start,74);
	insertfront(&start,41);
	insertfront(&start,16);
	insertfront(&start,8);
	insertfront(&start,1);
	
	insertfront(&start2,84);
    insertfront(&start2,41);
	insertfront(&start2,16);
	insertfront(&start2,4);
	insertfront(&start2,2);
	
    cout<<"List is : \n";
	printlist(start);
	cout<<"\nAnother List is : \n";
	printlist(start2);
//	MergeList(&start,&start2,&List);
    cout<<"\nMerge List is : \n";
//	printlist(List);
	
	struct node *New = Merge(start,start2);
 	printlist(New);

return 0;
}


