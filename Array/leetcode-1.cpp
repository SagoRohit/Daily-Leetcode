#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // unordered_map<int, int> map;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     int compliment = target - nums[i];
        //     if(map.count(compliment)>0){
        //         return {map[compliment], i};
        //     }
        //     map[nums[i]]= i;
        // }
        // return {};
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {};
    }
};