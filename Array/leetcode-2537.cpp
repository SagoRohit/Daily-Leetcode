#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int i=0, j=0;
            long long result =0;
            unordered_map<int, int> mp;
            int n= nums.size();
            long long pairs=0;

            while(j<n){
                pairs+= mp[nums[j]];
                mp[nums[j]]++;

                while(pairs>=k){
                    result+= (n-j);
                    mp[nums[i]]--;
                    pairs-= mp[nums[i]];
                    i++;
                }
                j++;
            }
            return j;
        }
};