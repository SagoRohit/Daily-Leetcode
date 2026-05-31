#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class RandomizedSet {
public:
    vector<int> obj;
    unordered_map <int, int> ind;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it = ind.find(val);
        if(it!=ind.end())
            return false;
        obj.push_back(val);
        ind[val] = obj.size()-1;
        return true;
    }
    
    bool remove(int val) {
        auto it = ind.find(val);
        if(it==ind.end())
            return false;
        int index = it->second;
        int backval = obj.back();

        obj[index] = backval;
        ind[backval] = index;

        obj.pop_back();
        ind.erase(val);
        return true;
    }
    
    int getRandom() {
        return obj[rand()%obj.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */