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




struct TrieNode {
    int value;
    struct TrieNode *children[26];
    
};

struct Trie_t {
     int count;
     struct TrieNode *Root;
};

struct TrieNode *getNode()
 {
      struct TrieNode *NewNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
      NewNode->value = 0 ;
      for(int i = 0 ;i<26; i++)
        {
             NewNode->children[i] = NULL;
        }
        return NewNode;
 }

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct Trie_t *New = (struct Trie_t *)malloc(sizeof(struct Trie_t));
    New->Root = getNode();
    New->count=0;
    return New->Root;
     
    
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    
    int length = strlen(word),level,index;
    struct TrieNode *child = root;
    for(level = 0 ; level < length ; level++)
      {
           index = word[level] - 'a';
           if(!child->children[index])
           child->children[index] = getNode();
           
           child = child->children[index];
      }
      child->value = 1;
    
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    
    int length = strlen(word),level,index;
    struct TrieNode *child = root;
      for(level = 0; level < length ; level++)
       {
            index = word[level] -'a' ;
            if(!child->children[index])
            return 0;
            child = child->children[index];
       }
       return (child!=0 && child->value);
    
    
    
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int level,length = strlen(prefix),index;
    struct TrieNode *child = root;
    for(level = 0 ; level < length ; level++)
      {    
           index = prefix[level] - 'a' ;
      	   if(!child->children[index])
      	   return 0 ;
      	   
      	 child = child->children[index];
      }
      return 1 ;
    
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
	if (root != NULL) {
        for (int i = 0; i < 26; i++) {
            trieFree(root->children[i]);
        }
            free(root);
    }
    
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);

int main()
{
  struct TrieNode* node = trieCreate();
  insert(node, "some");
  cout<<search(node, "some")<<" \n";
  cout<<" starts with : "<<startsWith(node,"s1o")<<"\n";
  trieFree(node);
  cout<<search(node, "some")<<" \n";


return 0;
}
