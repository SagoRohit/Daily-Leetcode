#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int result=nums[0];
        bool nonzero = false;
        if(result!=0)
            nonzero = true; // hardcoded e.g., [6,0]
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=0)
                nonzero = true;
            result ^= nums[i];
        }
        // cout<<result;
        if(!nonzero)
            return 0;
        if(result!=0)
            return nums.size();
        return nums.size()-1;
    }
};