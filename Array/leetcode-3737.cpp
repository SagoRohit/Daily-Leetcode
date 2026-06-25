#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        for(int start = 0; start<nums.size(); start++) {
            int count = 0;
            for(int end = start; end<nums.size(); end++) {
                if(nums[end]==target)
                    count++;
                if((count*2) > (end - start + 1))
                    result += 1;
            }
            
        }
        return result;
    }
};