#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc = 0, oc =0, tc =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                zc++;
            else if(nums[i]==1)
                oc++;
            else
                tc++;
        }
        int i=0;
        while(zc>0 && i<nums.size()){
            nums[i++]=0;
            zc--;
        }
        while(oc>0 && i<nums.size()){
            nums[i++]=1;
            oc--;
        }
        while(tc>0 && i<nums.size()){
            nums[i++]=2;
            tc--;
        }
        
    }
};