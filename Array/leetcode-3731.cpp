#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto it = min_element(nums.begin(), nums.end());
        int lower = *it;
        it = max_element(nums.begin(), nums.end());
        int upper = *it;
        vector<int> result;
        unordered_set<int> keep(nums.begin(), nums.end());
        for(int i= lower; i<=upper; i++){
            if(keep.count(i)==0)
                result.push_back(i);
        } 
        return result;
    }
};