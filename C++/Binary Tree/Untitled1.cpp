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

int main()
{  int t, i = 0 ;
   int a[200];
  cin>>t;
  int k = t  ;
  while(k--)
   {
   	 S(a[i]);
   	 i++;
   }  
  sort(a,a+t);
  int max =  - a[0] + a[t-1] ;
  int b[200];
  b[0] = a[t-1];
  b[t-1] = a[0] ;
  F(i,1,t-1)
  b[i] = a[i];
  
  F(i,0,t)
  cout<<b[i]<<" ";



return 0;
}

