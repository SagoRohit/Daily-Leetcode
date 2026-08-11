#include<bits/stdc++.h>
#include <parallel/compatibility.h>
using namespace std;
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix=nums[0];
        unordered_set<int> hash(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]+1)
                prefix += nums[i];
            else
                break;
        }
        while(hash.count(prefix)){
            cout<<prefix<<endl;
            Sleep(1000);
            prefix++;
        }
        return prefix;
    }
};
int main(){
    Solution sol;
    vector<int> num = {3,4,5,1,12,14,13};
    cout<<sol.missingInteger(num)<<endl;
    return 0;
}