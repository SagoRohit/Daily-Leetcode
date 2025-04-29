#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        using ll = long long;
        long long countSubarrays(vector<int>& nums, int k) {
            ll result = 0;
            int i = 0, m = nums.size();
            int cnt = 0;
            int el = -1;
    
            for (int c : nums) {
                if (c > el)
                    el = c;
            }
    
            for (int j = 0; j < m; j++) {
                if (el == nums[j])
                    cnt++;
                while (cnt >= k) {
                    if (nums[i] == el)
                        cnt--;
                    i++;
                }
                result += i;
            }
            return result;
        }
    };