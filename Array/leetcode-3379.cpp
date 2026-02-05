#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            int ind = ((nums[i]+i)%n+n)%n; //to normalize in range [0,n]
            result[i]=nums[ind];
        }
        return result;
    }
};