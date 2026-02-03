#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1 && nums[i]<nums[i+1])
            i++;
        if(i==0 || i==n-1)
            return false;
        int mid=i;
        while(i<n-1 && nums[i]>nums[i+1])
            i++;
        if(i==mid || i==n-1)
            return false;
        while(i<n-1 && nums[i]<nums[i+1])
            i++;
        return i==n-1;
    }
};