#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int start = 0;
        int end = 0;
        int n = nums.size();
        int longest = -1;
        while (start <= end and end < n)
        {
            cout<<start<<" "<<end<<" "<<nums[end]<<" "<<freq[nums[end]]<<endl;
            if (freq[nums[end]] < k)
                { // good to go
                    freq[nums[end]]++;
                    end++;
                }
                else
                {
                    longest = max(longest, end - start);
                    freq[nums[start]]--;
                    start++;
                }
        }
        longest = max(longest, end - start);
        return longest;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,1,2,3,1,2};
    cout<<sol.maxSubarrayLength(nums, 2);
    return 0;
}