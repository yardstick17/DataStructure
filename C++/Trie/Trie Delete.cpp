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
struct trie_node
{
	  int value;
	  trie_node *children[26];
};
struct trie_t
 {
 	 trie_node *root;
 	 int count;
 };


 struct trie_node *getNode()
  {
  	 struct trie_node *Node;
  	 Node = (struct trie_node *)malloc(sizeof(struct trie_node));
  	 Node->value = 0 ;
	 F(i,0,26)
	 {
	 	 Node->children[i] = NULL;
	 }
  	 return Node;
  }


 void insert(struct trie_t *trie,char *key)
  {

  	   int level,length = strlen(key),index;
  	   struct trie_node *child;
  	   trie->count++;
	   child = trie->root;
	   for(level = 0 ; level < length ; level++)
	     {
	       index = key[level] - 'a';
		   cout<<"\nIndex is: "<<index<<"\n";
		   if(!child->children[index])
		    {
		    	 child->children[index] = getNode();

		    }
			child = child->children[index];
		  }


		  child->value = trie->count;

	}

	int search(struct trie_t *trie,char *key)
	  {
	  	   int level,length = strlen(key),index;
	  	   struct trie_node *child;

	  	   child = trie->root;

	  	   for(level = 0 ; level < length ; level++)
	  	     {
	  	     	 index = key[level]-'a';

				if(!child->children[index])
	  	     	  return 0;

				child = child->children[index];

	  	     }
	  	     return (0 != child && child->value);

	  }



  void initialize(struct trie_t *trie)
    {
    	 trie->root = getNode();
    	 trie->count = 0 ;
    }

    int itisfree(struct trie_node *node)
      {
      	 F(i,0,26)
      	  {
      	  	 if(node->children[i])
      	  	 return 0;
      	  }
      	  return 1;
      }


      int leafnode(struct trie_node *node)
        {
        	 return (node->value!=0);
        }
    bool Delete(struct trie_node *node,char *key,int level,int len)
     {
        if(node)
		 {
		 	 if(level== len)
		 	   {

		 	   	 if(node->value)
		 	   	   {
		 	   	   	       node->value=0;
			 	   	   	   if(itisfree(node))
			 	   	   	    {
			 	   	   	    	 return true;
			 	   	   	    }
			 	   	   	    return 0;
		 	   	   }


		 }
		 else
		 {
		    	  int index = key[level] - 'a' ;
		    	  if(Delete(node->children[index],key,level+1,len))
		    	  {
		    	  	 free(node->children[index]);
		    	  	 return (!leafnode && itisfree(node));
		    	  }

		 }
     }
   return 0;
 }


    void DeleteKey(struct trie_t *trie,char *key)
     {
     	  int len = strlen(key);
     	  if(len)
     	   {
     	   	 Delete(trie->root,key,0,len);
     	   }
     }
int main()
{
  char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  struct trie_t *trie;

  char output[][32] = {"Not present in trie", "Present in trie"};
  trie = (struct trie_t*)malloc(sizeof(struct trie_t));
  initialize(trie);
  
      printf("%s --- %s\n", "the", output[search(trie, "the")] );

  F(i,0,8)
  {
  	 insert(trie,keys[i]);
  }
  //DeleteKey(trie,keys[0]);

    printf("%s --- %s\n", "the", output[search(trie, "the")] );
    printf("%s --- %s\n", "these", output[search(trie, "these")] );
    printf("%s --- %s\n", "their", output[search(trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(trie, "thaw")] );





return 0;
}

