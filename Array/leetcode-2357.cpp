#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> num(nums.begin(), nums.end());
        return (num.count(0)==0)? num.size(): num.size()-1;
    }
};