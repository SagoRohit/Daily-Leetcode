#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n= nums.size();
            int pairs=0;
            for(int i=0; i<n-1; i++){
                int j=i+1;
                for(; j<n; j++){
                    if(nums[i]==nums[j]){
                        if((i*j)%k==0)
                            pairs++;
                    }
                }
            }
            return pairs;
        }
    };