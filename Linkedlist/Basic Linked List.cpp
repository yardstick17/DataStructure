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

               cout<<"Check ? Odd "<<endl;

          }
          else
          {
               list2 = slw->next ;         
			   cout<<"Check ?Even "<<endl;

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

  
  
  
  
  
int main()
{
    int t;
    struct node *start =NULL;
    
	insertfront(&start,7);
	//insertfront(&start,7);
/*  insertfront(&start,8);
    insertfront(&start,7);
	/*insertfront(&start,6);
	insertfront(&start,8);
	insertfront(&start,1);
	*/
    cout<<"List is : \n";
	printlist(start);
	cout<<"IsPalinDrome : "<<isPalindrome(start)<<endl;
 
return 0;
}


