#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        double minimumAverage(vector<int>& nums) {
            int n = nums.size();
            vector<double> avg(n/2);
            sort(nums.begin(), nums.end());
            int j = n-1;
            for(int i=0; i<n/2; i++){
                avg[i]= (nums[i]+nums[j])/2.0;
                j--;
            }
            sort(avg.begin(), avg.end());
            return avg[0];
        }
    };
int main(){
    Solution sol;
    vector<int> nums={7,8,3,4,15,13,4,1};
    cout<<sol.minimumAverage(nums)<<endl;
    return 0;
}