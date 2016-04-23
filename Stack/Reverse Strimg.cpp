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
	 char *character;
	 int capacity;
	 int top;
};

struct stack *createStack(int capacity)
 {
 	 struct stack *stk = (struct stack *)malloc(sizeof(struct stack));
 	 stk->top = -1 ;
 	 stk->character = (char *)malloc(capacity*sizeof(char));
 	 stk->capacity = capacity ;
 	 return stk;
 }
 int isEmpty(struct stack *stk)
  {
  	 if(stk->top== -1)
  	 return 1;
  	 else
  	 return 0;
  }
  
  int isFull(struct stack *stk)
   {
   	 if(stk->top == stk->capacity - 1 )
   	 return 1;
   	 else
   	 return 0;
   }
   
   void push(struct stack *stk, char c)
    {
    	 if(!isFull(stk))
    	  {
    	  	 stk->character[++stk->top] = c ; 
    	  }
    }
    char pop(struct stack *stk)
     {   char c ;
     	 if(!isEmpty(stk))
     	 {
     	 	 c = stk->character[stk->top--];
     	 	return c;
     	 }
     	 return -1;
     }
int main()
{
  
  struct stack *stk = createStack(10); 
  string str;
  cin>>str;
  F(i,0,str.length())
  push(stk,str[i]);
  
  F(i,0,str.length())
  cout<<pop(stk);
  




return 0;
}

