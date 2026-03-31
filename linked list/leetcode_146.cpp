#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

// Brute force solution using vector as the cache

// class LRUCache {
// public:
//     vector<pair<int, int>> cache;
//     int n;
//     LRUCache(int capacity) {
//         n = capacity;
//     }
    
//     int get(int key) {
//         for(int i=0; i<cache.size(); i++){
//             if(cache[i].first==key){
//                 int val = cache[i].second;

//                 pair<int, int> temp = cache[i];
//                 cache.erase(cache.begin()+i);
//                 cache.push_back(temp);

//                 return val;
//             }
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i=0; i<cache.size(); i++){
//             if(cache[i].first==key){
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key,value});
//                 return;
//             }
//         }
//         if(cache.size()==n){
//             cache.erase(cache.begin());
//             cache.push_back({key,value});
//         }else{
//             cache.push_back({key,value});
//         }
//     }
// };


// now we will go for the optimal solution. to obtain an optimal solution,
// we will use doubly linked list (using cpp stl for simplicity) data structure
// to get and put item in a time complexity of O(1).
class LRUCache {
public:
    list<int> dll; // in dll, we will store the key of the items
    map<int, pair<list<int>::iterator, int>> mp; // [key]-> [address, value]
    int n; // max size allowed in the cache

    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRU(int key){ // this function makes the key node recently used
        // it first get the go to the node, delete it, and then push it in the front
        // as our policy is that freshers will be in the front and least used nodes 
        // at back of our list
        dll.erase(mp[key].first); // delete the node(key) from the list, so that we 
                                // can move it to the front of the list according to our policy
        dll.push_front(key); // push the node in the front
        mp[key].first= dll.begin(); // now update the address of this node (key)

    }
    int get(int key) {
        if(mp.find(key)==mp.end()){ // if not present in the map, return -1
            return -1;
        }
        makeRU(key); // as we access it, make it recent used 
        return mp[key].second; // return the value
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            makeRU(key); // as we update the value, means we accessed it, 
                        //needed to be made recently used, means we need 
                        //to put this in the front of the list according to our policy
            return;
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(), value};
            n--;
        }
        if(n<0){ // if the list node count exceed the cache size, we need to handle this
                    // one by erasing the least recently used key.
            int removed_key = dll.back(); // we need to get the key, so that we can erase it also from the map
            mp.erase(removed_key);
            dll.pop_back(); // erasing it from our list
            n++;
        }
    }
};