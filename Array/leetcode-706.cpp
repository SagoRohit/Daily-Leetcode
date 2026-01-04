#include<iostream>
#include<vector>
using namespace std;
class node {
public:
    int key;
    int value;
    node* next;
    node(int k=-1, int val=-1, node* n=nullptr): key(k), value(val), next(n) {}
};
class MyHashMap {
private:
    vector<node*> map;
public:
    MyHashMap() {
        map.resize(1000);
        for(int i=0; i<1000; i++)
        {
            map[i]= new node();
        }
    }
    int hash(int key)
    {
        return key%1000;
    }
    void put(int key, int value) {
        int hash_key = hash(key);
        node* curr = map[hash_key];
        while(curr->next)
        {
            if(curr->next->key==key)
            {
                curr->next->value=value;
                return;
            }
            curr= curr->next;
        }
        curr->next = new node(key, value);
    }
    
    int get(int key) {
        int hash_key = hash(key);
        node* curr = map[hash_key];
        while(curr->next)
        {
            if(curr->next->key==key)
            {
                return curr->next->value;
            }
            curr= curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        node* curr = map[hash_key];
        while(curr->next)
        {
            if(curr->next->key==key)
            {
                node* temp  = curr->next;
                curr->next= curr->next->next;
                delete temp;
                return ;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */