 			/* AK_47*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string.h>
#include<math.h>
#include<queue>
#include<stdlib.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define V(x) vector<x>
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
void Markmultiples(bool *prime,int n)
{
	  prime[0] = 0 ;
	  prime[1] = 0 ;
	  prime[2] = 1 ;
	  int j = 2;
	  for(int j = 2 ;j <= sqrt(n); j++)
	  {
	  
	    for(int i = 2 ; i*j <= n ;i++)
	     {
	     	   prime[i*j] = 0 ;
	     }
      }
      
	
}
int countPrimes(int n)
 {
 	 bool prime[999999];
 	 memset(prime,1,sizeof(prime));
 	 int count=0;
 	 Markmultiples(prime,n);
 	 for(int i = 1 ; i < n; i++)
 	   {
 	   	 if(prime[i])
 	   	 count++;
 	   }
 	   
 	 return count;
 }


 int main()
  {
    cout<<countPrimes(2)<<endl;
    
    
  	 
  return 0 ;
  
  }
