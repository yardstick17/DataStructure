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
void Merge(int a[] ,int mid , int low ,int high)
{
	    int L[mid - low + 1 ] ;
	    int R[high - mid + 1] ;
	    int i , j = 0 ; 
	    
		 for(i = low ; i <= mid ; i++)
	     L[j++] = a[i] ;
		 
		 j = 0 ; 
		 
		 for(i = mid + 1 ; j < high ;j++)
		 R[j++] = a[i] ;
		 
		 i = low ;
		 int li = 0 , ri = 0 ;
		 while( i < high)
		 {
		 	  
			   if(li <= mid && L[li] < R[ri])
		 	   {
		 	   	   a[i] = L[li] ;
		 	   	   li++;
		 	   }
		 	   else
		 	   {
		 	   	 a[i] = R[ri] ;
		 	   	 ri++;
		 	   }
		 	   i++;
		 }
	}
		 
		  

void mergeSort(int a[] , int low  , int high)
{
  int mid = high + (high - low ) / 2 ;
	  if(low < high)
	  {
	    mergeSort(a,low ,mid);
	    mergeSort(a , mid+1, high);
	    Merge(a , mid , low , high) ;
      }
}
int main()
{
 int a[] = { 1,2,3,5,4,1,5,2,5,5} ;
  mergeSort(a ,0 , 9) ;
  F(i , 0 , 9)
   cout<<a[i]<<" ";





return 0;
}
