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
struct Stack {
	 int top;
	 int *array;
	 int capacity;
};



struct Stack *createStack(int capacity)
  {
	 struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	   stack->capacity = capacity;
	   stack->array = (int *)malloc(stack->capacity*sizeof(int));
	   stack->top= -1;
	 return stack;
  }

int isFull(struct Stack *stack)
  {
     return (stack->top == stack->capacity-1);
  }
  
 int isEmpty(struct Stack *stack)
  {
  	  return stack->top== -1;
  }

 void push(struct Stack *stack,int num)
  { 
    
  	if( !isFull(stack))
	   {
	   	   stack->array[++stack->top] = num;
	   	   cout<<"pushed Item is : "<<stack->array[stack->top]<<"\n";
	       return;
	   }
	   cout<<"not pushed!!!";
  }
  
  int  pop(struct Stack *stack)
  {
  	 int num = -1;
  	if(!isEmpty(stack))
  	{
  	  num = stack->array[stack->top--];	 
  	}
  	return num;
  }
  void ReverseStack(struct Stack *stk)
   {  
        

   }
  
  
int main()
{
    struct Stack *stack = createStack(100);
    push(stack,5);
    push(stack,10);
    push(stack,25);
    push(stack,57);
    push(stack,05);
    push(stack,42);
    ReverseStack(stack);
    //cout<<"Pop: -> "<<pop(stack);
     
    
    //cout<<"\nTop Element is : "<<peek(stack);
    
return 0;
}

