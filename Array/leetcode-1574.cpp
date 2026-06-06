#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum(nums.size(),0);
        vector<int> rightsum(nums.size(),0);
        int i=1, j=nums.size()-2;
        while(i<nums.size() and j>=0){
            leftsum[i]=nums[i-1]+leftsum[i-1];
            rightsum[j]=nums[j+1]+rightsum[j+1];
            i++;
            j--;
        }
        vector<int> result(nums.size());
        for(int i=0; i<nums.size(); i++){
            result[i] = abs(leftsum[i]-rightsum[i]);
        }
        return result;
    }
};