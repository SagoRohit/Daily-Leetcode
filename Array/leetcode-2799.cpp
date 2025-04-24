#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            unordered_set<int> set(nums.begin(), nums.end());
            int c = set.size();
            int i=0, j=0;
            int result=0;
            unordered_map<int, int> mp;
            while(j<n){
                mp[nums[j]]++;
                while(c==mp.size()){
                    result+= (n-j);
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                    i++;
                }
                j++;
            }
            return result;
        }
};
int main(){

    return 0;
}
