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

struct StackNode{
	 int data;
	 struct StackNode *next;
};
 int isEmpty(struct StackNode *stack)
  {
  	 return !stack;
  }

 struct StackNode *NewNode(int data)
  {
  	 struct StackNode *stackNode =(struct StackNode *)malloc(sizeof(struct StackNode));
     stackNode->data = data;
     stackNode->next = NULL;
     return stackNode;
  }
  void push(struct StackNode **stack,int num)
   {
   	 struct StackNode *Node = NewNode(num);
		 Node->next = *stack;
		 *stack = Node;
		 cout<<"Pushed In stack "<<num<<" \n"<<endl;
   }
   int pop(struct StackNode **stack)
   { 
     if(!isEmpty(*stack))
       {
       	  struct StackNode *tmp = *stack;
       	  *stack = tmp->next;
       	  int num = tmp->data;
       	  free(tmp);
       	  return num;
       }
       return -1;
       
   }

int main()
{
   struct StackNode *stack= NULL;
   push(&stack,5);
   push(&stack,10);
   push(&stack,15);
   cout<<"Pop : "<<pop(&stack);
   cout<<"\nPop : "<<pop(&stack);
   cout<<"\nPop : "<<pop(&stack);
   cout<<"\nPop : "<<pop(&stack);


return 0;
}

