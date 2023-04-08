#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key, value;
        Node *prev;
        Node *next;

        Node(int k, int v){
            key=k;
            value=v;

            prev=NULL;
            next=NULL;
        }
};

class LRUCache {
public:
    int size=0;
    map<int, Node*> cache;
    Node *head = new Node(0,0);
    Node *tail = new Node(0,0);
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* node){
        Node* temp=head->next;
        
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    
    void deleteNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        // delete node;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node *ptr = cache[key];
            cout<<"Using: "<<ptr->key<<endl;
            
            int value=ptr->value;

            cache.erase(key);
            deleteNode(ptr);
            
            addNode(ptr);
            cache[key]=head->next;
            
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node *ptr = cache[key];
            cout<<"Update: "<<ptr->key<<endl;
        
            cache.erase(key);
            deleteNode(ptr);
        }
        if(cache.size()==size){
            Node *ptr = tail->prev;
            cout<<"Delete: "<<ptr->key<<endl;
            
            cache.erase(ptr->key);
            deleteNode(ptr);
        }
            
        Node *node=new Node(key, value);
        cout<<"Insert: "<<node->key<<endl;
        addNode(node);
        cache[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */