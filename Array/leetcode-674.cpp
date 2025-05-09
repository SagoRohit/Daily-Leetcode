#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int result=-1;
        while(j<n-1){
            if(nums[j]>=nums[j+1]){
                result = max(result, j-i+1);
                j++;
                i=j;
            }
            else j++;
        }
        result = max(result, j - i + 1);
        return result;
    }
};