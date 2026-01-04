#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>
using namespace std;
class Solution {
public:
        // int n= nums.size()/2;
        // unordered_map<int, int> map;
        // for(auto num: nums)
        // {
        //     map[num]++;
        // }
        // int maxferq=0;
        // int element;
        // for(const auto& pair: map)
        // {
        //     if(pair.second > maxferq)
        //     {
        //         maxferq = pair.second;
        //         element = pair.first;
        //     }
        // }
        // return element;
    int repeatedNTimes(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxfreq = 0;
    int element = nums[0];
    int i = 0;

    while (i < nums.size()) {
        int count = 0;
        int currentVal = nums[i];
        
        // Count all occurrences of the current value
        while (i < nums.size() && nums[i] == currentVal) {
            count++;
            i++; 
        }

        if (count > maxfreq) {
            maxfreq = count;
            element = currentVal;
        }
    }
    return element;
}
};