#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        map<char, TrieNode*> children;
        bool endOfWord;
    
        TrieNode(){
            endOfWord=false;
            
            for(int i=0; i<26; i++){
                children['a'+i]=NULL;
            }
        }
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node=root;
        
        for(auto ch: word){
            if(!node->children[ch]){
                node->children[ch]=new TrieNode();
            }
            node=node->children[ch];
        }
        
        node->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode *node=root;
        
        for(auto ch: word){  
            if(!node->children[ch]){
                return false;
            }
            node=node->children[ch];
        }
        
        return node->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node=root;
        
        for(auto ch: prefix){
            if(!node->children[ch]){
                return false;
            }
            node=node->children[ch];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */