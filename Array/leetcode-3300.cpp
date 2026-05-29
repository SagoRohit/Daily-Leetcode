#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            nums[i] = digitsum(nums[i]);
            mini = min(mini, nums[i]);
        }
        return mini;
    }
};
int main(){
    Solution sol;
    vector<int> vec{10,12,13,14};
    cout<<sol.minElement(vec)<<endl;
    return 0;
}