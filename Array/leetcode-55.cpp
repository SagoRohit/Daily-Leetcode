#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int furthest = 0;
        int n = nums.size()-1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > furthest) // if my i is beyond my furthest point
                return false;

            furthest = max(furthest, i + nums[i]); // calculate futhest point
            if(furthest>=n)
                return true;
        }
        return false;
    }
};