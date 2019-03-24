			/* AK_47*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string.h>
#include<Queue>
#include<stdlib.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define V(x) vector<x>
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
struct Queue{
	 int capacity,front,rear,item,size;
	 int *array;
};

struct Queue *CreateQueue(int capacity)
 {
 	 struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
 	// Q->capcacity = capacity - 1;
 	 Q->capacity = capacity;
	  Q->front = Q->size = 0 ;
 	 Q->rear = capacity - 1;
 	 Q->array = (int *)malloc(capacity * sizeof(int));
 	 return Q;
 }
 
 int isFull(struct Queue *Q)
  {
  	  if(Q->size == Q->capacity)
  	  return 1 ;
  	  else
  	  return 0;
  }
  int isEmpty(struct Queue *Q)
   {
   	 if(Q->size==0)
   	 return 1;
   	 else
   	 return 0;
   }
 
 void push(struct Queue *Q,int num)
  {
  	  if(!isFull(Q))
  	   { 
		 Q->rear = (Q->rear + 1 ) % Q->capacity;
		 Q->size = Q->size + 1 ;
  	   	 Q->array[Q->rear] = num ;
  	   	 cout<<"Pushed Element is : "<<num<<"\n";
  	   }
  }
  int pop(struct Queue *Q)
   {   int item;
   	   if(!isEmpty(Q))
   	     {
   	     	 item = Q->array[Q->front];
   	     	 Q->front = (Q->front + 1 ) % Q->capacity;
   	     	 Q->size = Q->size - 1 ;
   	     	 cout<<"Popped Element is: "<<item<<"\n";
   	     	 
   	     }
   }
   int front(struct Queue *Q)
     {  int item;
     	 if(!isEmpty(Q))
     	  {
     	  	 item = Q->array[Q->front];
     	  }
     	  return item;
     }
int main()
{
  struct Queue *Q = CreateQueue(5);
  push(Q,1);
  push(Q,4);
  push(Q,74);
  push(Q,14);
  pop(Q);
  pop(Q);//,15)
  push(Q,147);





return 0;
}

