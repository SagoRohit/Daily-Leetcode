#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1=51;
        int min1ind;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<min1){
                min1=nums[i];
                min1ind=i;
            }
        }
        int min2=51;
        for(int i=1; i<nums.size(); i++){
            if(min2> nums[i] && min2>=min1 && i!=min1ind){
                min2 = nums[i];
            }
        }
        return nums[0]+min1+min2;
    }
};