#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        unordered_set<int> seta;
        unordered_set<int> setb;
        vector<int> result;
        int count=0;
        for(int i=0; i<a.size(); i++){
            int tempcount = 0;
            seta.insert(a[i]);
            setb.insert(b[i]);
            if(setb.find(a[i])!=setb.end())
                tempcount++;
            if(seta.find(b[i])!=seta.end())
                tempcount++;
            if(a[i]==b[i])
                tempcount = 1;
            count += tempcount;
            result.push_back(count);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int count=0;
        unordered_map<int, int> mp;
        for(int i=0; i<a.size(); i++){
            mp[a[i]]++;
            if(mp[a[i]]==2)
                count++;
            mp[b[i]]++;
            if(mp[b[i]]==2)
                count++;
            result.push_back(count);
        }
        return result;
    }
};