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
long long a[100005];

int main()
{
  long long int t, k ;
  cin>>t;
k = t ;
  int i = 0 ;
  while(k--)
  {
  	 cin>>a[i];
  	 i++;
  }
  sort(a,a+t,greater<long long>());
  F(i,0,t)
  cout<<a[i]<<" ";





return 0;
}

