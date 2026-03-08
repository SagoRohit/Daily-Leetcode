#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        int jumps=0;
        int farthest= INT_MIN;
        int current_end=0;
        for(int i=0; i<n-1; i++)
        {
            farthest= max(farthest, i+nums[i]);
            if(i==current_end)
            {
                jumps++;
                current_end= farthest;
            }
            if(current_end>=n-2)
                break;

        }
        return jumps;
    }
};
int main(){
    Solution sol;
    vector<int> nums= {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout<<sol.jump(nums);
    return 0;
}