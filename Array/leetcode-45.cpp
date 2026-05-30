#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int current_end =0;
        int n = nums.size();
        int farthest = 0;
        int jump =0;
        for(int i=0; i<n-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i==current_end){
                jump++;
                current_end = farthest;
            }
            if(current_end>=n-1)
                break;
        }
        return jump;
    }
};