#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        vector<int> diff(n,0);
        for(int i=0; i<m; i++){
            int start = q[i][0];
            int end = q[i][1];
            
            diff[start]+=1;
            if(end+1<n)
                diff[end+1]-=1;
        }
        vector<int> result(n,0);
        int cumsum=0;
        for(int i=0; i<n; i++){
            cumsum+= diff[i];
            result[i]=cumsum;
        }
        for(int i=0; i<n; i++){
            if(result[i]<nums[i])
                return false;
        }
        return true;
    }
};