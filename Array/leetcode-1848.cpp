#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target)
            {
                mini = min(mini, abs(i-start));
            }
        }
        return mini;
    }
};
class Solution1 {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums[start]==target)
            return 0;
        int ind = 1;
        while(true)
        {
            if(start-ind>=0 and nums[start-ind]==target)
                return ind;
            if(start+ind<nums.size() and nums[start+ind]==target)
                return ind;
            ind++;
        }
        return -1;
    }
};