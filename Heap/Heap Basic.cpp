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
void swap(int *a,int *b)
 {
 	 int k = *a ;
 	 *a = *b;
 	 *b = k ;
 }
class MinHeap
  {
  	  int *h;
  	  int capacity;
  	  int size;
  	  
  	  public:
		void insert(int k);
        void decreaseKey(int i, int value);
		MinHeap(int);
  	  	void MinHeapify(int);
  	  	void deleteKey(int i);
		int extractMin();
		void print();
		void Sort();

  	  	
  	  	int parent(int i)
  	  	{
  	  	  return (i-1)/2;
  	  	}
  	  	int left(int i)
		{
		  return 2*i + 1;
  	  	}
  	  	int right(int i)
		{
	      return 2*i + 2 ;
	    }
		
		int getMin()
		{
		  return h[0];
		}
	};
MinHeap::MinHeap(int cap)
	  {
	  	 capacity = cap;
	  	 size = 0 ;
	  	 h = new int[cap];
	  }
void MinHeap::insert(int key)
	  {
	  	 
		 if(size == capacity)
	  	  return;
	  	  
	  	 h[size] = key ;
		 size++;
		 int i = size -1 ;
		 while(i!=0 && h[parent(i)] > h[i])
		 {
		 	 swap(&h[i],&h[parent(i)]);
		 	 i = parent(i);
		 }
		    
	  }
void MinHeap::decreaseKey(int  i ,int value)
 {
 	 h[i] = value;
 	 while(i!=0 && h[parent(i)] > h[i])
 	   {
 	   	  swap(&h[i],&h[parent(i)]);
 	   	  i = parent(i);
 	   }
 }
 int MinHeap::extractMin()
  {
  	 if(size<=0)
  	   return -1;
  	 if(size==1)
  	   return h[0],size--;
  	   
  	   int root = h[0];
  	   h[0] = h[size-1];
  	   size--;
  	   MinHeapify(0);
  	   return root;
  }
  
void MinHeap::deleteKey(int i)
 {
 	 decreaseKey(i,-9999);
 	 extractMin();
 }
 
 void MinHeap::MinHeapify(int i)
   {
   	   int l = left(i);
   	   int r = right(i);
   	   int smallest = i ;
   	   if(l<size && h[l] < h[i])
   	   smallest = l;
   	   if(r<size && h[r]<h[smallest])
   	   smallest = r ;
   	   
   	   if(smallest!=i)
   	    {
   	    	 swap(&h[i],&h[smallest]);
   	    	 MinHeapify(smallest);
   	    }
   	   
   } 
   void MinHeap::print()
    {
    	 F(i,0,capacity)
    	   {
    	   	 cout<<h[i]<<" ";
    	   }
    }
	  
   void MinHeap::Sort()
	   { 
	      int i = capacity-1;
	       while(i>=1)
	        {
	        	  int root = h[0];
	        	  h[0] = h[size-1];
	        	  h[size-1] = root ;
				  size--;
				  MinHeapify(0);
				  i--;
	        	  
	        }
	      
	       
	   }
int main()
{ 
    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    //h.deleteKey(1);
    h.insert(15);
    h.insert(51);
    h.insert(42);
    h.insert(45);
        h.insert(14);
    h.insert(87);
    h.insert(7);
    h.insert(12);
    h.insert(21);

    //F(i,0,10)
    h.print();
    h.Sort();
    cout<<"\n";
     h.print();
	//cout<<h[i]<<"\n";
    // cout << h.extractMin() << " ";
    //cout << h.getMin() << " ";
    //h.decreaseKey(2, 1);
    //cout << h.getMin();

return 0;
}

