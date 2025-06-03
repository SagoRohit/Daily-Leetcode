#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, j=2;
        int closest= nums[0]+nums[1]+nums[2];
        for(int i=0; i<n; i++)
        {
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(abs(target-sum)<abs(target-closest))
                    closest= sum;
                if(sum<target)
                    left++;
                else if(sum>target)
                    right--;
                else    
                    return target;
            }
        }
        return closest;
    }
};