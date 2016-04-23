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
struct stack {
	 int i,hi;
	 int *a;
	 int capacity,top;
};
struct stack *createStack(int capacity){
	 struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
	 stk->capacity = capacity;
	 stk->top = -1;
	 stk->a = (int *)malloc(capacity * sizeof(int));
	 return stk; 
}
int isFull(struct stack *stk)
 {
 	 if(!stk->top == stk->capacity - 1)
 	  {
 	  	  return 1;
 	  }
 	  else
 	  return 0;
 }
 int isEmpty(struct stack *stk)
  {
  	 if(!stk->top== -1)
  	  {
  	  	 return 1;
  	  	 
  	  }
  	  else
  	  return 0;
  }
 void push(struct stack *stk,int n)
  {
  	 if(!isFull(stk))
  	  {
  	  	 stk->a[++stk->top] = n;
  	  }
  } 
  int pop(struct stack *stk)
   { int p;
   	 if(!isEmpty(stk))
   	  {
   	  	 p = stk->a[stk->top--];
   	  	 return p;
   	  }
   	  
   }
   int peep(struct stack *stk)
     {   int c ;
     	 if(!isEmpty(stk))
     	  {
     	  	 c = stk->a[stk->top];
     	  }
     	  return c;
     }

int StockSpan(int *a,int size)
{
	     struct stack *stk = createStack(50);
	     int ans[100];
	     push(stk,a[0]);
         memset(ans,0,sizeof(ans));
         ans[0] = 1;
		 F(i,1,size)
		 {  
		    while(!isEmpty(stk) && peep(stk)<a[i])
		    {   
		       pop(stk);  	
		    }
		    if(!isEmpty(stk))
		     ans[i] = i - stk->top;
		    else
		     ans[i] = i + 1 ;
		     
		     push(stk,a[i]);
		 
		 }		 	     
F(i,0,size)
cout<<ans[i]<<" ";	     

}
int main()
{

  int t,i,a[100];
  i = 0 ;
  S(t);
  while(t--)
   {
   	 S(a[i]);
   	 i++;
   }
    StockSpan(a,i);
   //F(i,0,5)
   //cout<<ans[i]<<" ";
   
   




return 0;
}

