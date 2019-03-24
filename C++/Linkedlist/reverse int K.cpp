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

struct node *reverse(struct node *head)
  {
      if( head == NULL | head->next== NULL)
      return head;
      
      struct node *prev  = NULL , *curr = head , *ptr = NULL;
      struct node *tmp = curr->next ;
      while( curr!= NULL) // & tmp != NULL)
       {
            curr->next = prev ;
            prev = curr ;
            curr = tmp ;
            if(tmp != NULL)
            tmp = tmp->next ;
       }
       ptr = prev ;
       cout<<"\nReverxze lIst is: \n";
       while(ptr!=NULL)
       {
            cout<<ptr->data<<" ";
            ptr = ptr->next ;
       }
       head = prev ;
       return head ;
  }
    bool isPalindrome(struct node* head) {
        
        struct node *ptr = head , *slw , *fast  ;
        struct node *list2 , *ptr2  ;
        fast = head ;
        slw = head  ;
   
        if(head == NULL || head->next == NULL)
        return true ;

        while(fast != NULL && fast->next!=NULL)
         {           
			fast = fast->next->next ;
			ptr = slw ;
			slw = slw->next ;
         }
         		     

         if(fast == NULL)
          {
               list2 = ptr->next ;
               ptr->next = NULL ;

               //cout<<"Check ? Odd "<<endl;

          }
          else
          {
               list2 = slw->next ;         
			  // cout<<"Check ?Even "<<endl;

               slw->next = NULL ;
          }

          list2 = reverse(list2);

          ptr = head ;
          ptr2 = list2 ;
          while(ptr2!=NULL)
            {
                 if(ptr->data != ptr2->data)
                 return false;
                 ptr = ptr->next ;
                 ptr2 = ptr2->next ;
                 
            }
            return true; 
          

}

 struct node *Intersect(struct node *start , struct node *start2)
 {
 	  struct node *a , *b ;
 	  a = start , b = start2 ;
 	  struct node *result = NULL ;
 	  struct node **ptr ;
 	  ptr = &result ;
 	  while(a!=NULL || b!=NULL)
 	  {
 	  		int x = 0  ; 
			int y = 0 ; 
		if(a!=NULL) x = a->data ;
 		if(b!=NULL) y = b->data ;
		
		if(x == y )
		{
			   insertfront(ptr , x);
			   ptr = &((*ptr)->next);
			  a = a->next ;
			  b = b->next ;
		} 
		else if(x < y) a = a->next ;
		
		else b = b->next ;
 	  }
 	  return result ;
 	  
 } 
void movenode(struct node **ptr , int data) // struct node **ptr)
 {
 	  struct node *newnode ;
 	  newnode = (struct node *)malloc(sizeof(struct node )) ;
 	  newnode->data = data ;
	  newnode->next = *ptr ;
 	  *ptr = newnode ;
 }
  
 struct node *reverseK(struct node *start , int k)
 {
 	  struct node *ptr , *current = start ,*nxt = NULL , *prev = NULL ;
 	  int count =  0 ;
	  while(current!=NULL && count++ < k)
	  {
	  	 nxt = current->next ;
	  	 current->next = prev ;
	  	 prev = current ;
	  	 current = nxt ;
	  }
	  if(nxt!=NULL)
	  start->next = reverseK( current , k);
	  
	  return prev ;
 } 
  
  
int main()
{
    int t;
    struct node *start =NULL;
    
	insertfront(&start,9);
	insertfront(&start,8);
	insertfront(&start,7);
    insertfront(&start,7);
	insertfront(&start,5);
	insertfront(&start,2);
	insertfront(&start,1);
	
    cout<<"List is : \n";
	printlist(start);
	
	struct node *start2 =NULL;
    
	insertfront(&start2,9);
	insertfront(&start2,7);
	insertfront(&start2,6);
    insertfront(&start2,6);
	insertfront(&start2,4);
	insertfront(&start2,2);
	insertfront(&start2,1);
	
    cout<<"\nSecond List is : \n";
	printlist(start2);
	
	start = reverseK(start , 3) ;
 	cout<<"\reversed K List is : \n";
	printlist(start);
	
return 0;
}


