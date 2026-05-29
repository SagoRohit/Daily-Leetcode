#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findmax(vector<int> &nums){
        int maxi = INT_MIN;
        int ind=-1;
        for(int i=0; i<nums.size(); i++){
            if(maxi<nums[i]){
                maxi = nums[i];
                ind = i;
            }
        }
        return ind;
    }
    int findmin(vector<int>& nums){
        int mini = INT_MAX;
        int ind = -1;
        for(int i=0; i<nums.size(); i++){
            if(mini>nums[i]){
                mini = nums[i];
                ind = i;
            }
        }
        return ind;
    }
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = findmin(nums);
        int maxi = findmax(nums);
        
        // 0 -> from the front, 1 -> from the back
        vector<vector<int>> story {{0,0},{0,1},{1,0},{1,1}}; // Fixed: {1,0} was missing
                                                            
        int result=INT_MAX;
        for(auto vec: story){
            int i = vec[0]; // for mini
            int j = vec[1]; // for maxi
            int total = 0;
            
            if(i == 0 && j == 0){
                // Both from front: just take the maximum index plus one
                total = max(mini, maxi) + 1;
            }
            else if(i == 1 && j == 1){
                // Both from back: just take the maximum distance from the back
                total = max(n - mini, n - maxi);
            }
            else {
                // Different directions: independent addition is correct
                total += (i == 0) ? (mini + 1) : (n - mini);
                total += (j == 0) ? (maxi + 1) : (n - maxi);
            }
            
            result = min(result, total);
        }
        return result;
    }
};
