#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod= 1e9+7;
        int n = nums.size();
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int count =0;
        for(int num: nums)
        {
            right[num]++;
        }
        for(int &num: nums)
        {
            right[num]--;
            int leftcount= left[num*2];
            int rightcount= right[num*2];


            count = (count + (1LL * rightcount * leftcount))%mod;
            left[num]++;
        }
        return count;
    }
};
