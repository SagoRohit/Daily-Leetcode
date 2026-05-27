#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        bool fault = 0;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>nums[(i+1)%n]){
                if(fault==1)
                    return 0;
                fault=1;
            }
        }
        return 1;
    }
};
// here we checked if the fault happens more than one time or not. if so, then return false. else at the end, 
// return true;
// now what is fault here? fault means if the curr element is larger than next elemenet. so if there
// is an one fault, it means, we can fix this error with a single rotation (fix means sort). So obviously
// if there is more that a single error, then we can't fix this using a single rotation. that's why, we return false here.