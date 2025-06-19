#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0;
        int count=0;
        while(i<n){
            int j=i;
            while(j<n && nums[j]-nums[i]<=k){
                j++;
            }
            count++;
            i= j;
        }
        return count;
    }
};