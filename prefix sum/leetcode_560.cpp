#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int prefsum=0;
        int result=0;
        map.insert({0,1});
        for(int i=0; i<nums.size(); i++){
            prefsum += nums[i];
            if(map.count(prefsum-k)){
                result += map[prefsum-k];
            }
            map[prefsum]++;
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,1,1};
    int k=2 ;
    cout<<sol.subarraySum(nums, k);
    return 0;
}