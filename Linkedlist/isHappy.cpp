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
bool isHappy(int n) {
        int k = n , a , t , num , sum  ;
        set<int>m;
        while(1)
         {    num = k ;
              sum =  0 ;
              while(num)
               {     t = num % 10 ;
                     num = (num - t)/10 ;
                     sum = sum + t*t ;
                     //cout<<num<<endl;
               }
             //  cout<<"Sum: "<<sum<<endl;
               if(sum == 1 )
               return true ;
               else if(m.find(sum) != m.end())
               return false ;
               m.insert(sum);
               k = sum ;
         }
    }
int main()
{
cout<<isHappy(169);





return 0;
}

