#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result=nums[0];
        int sim = nums[0];
        int count=1;
        int maxcount=-1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]==sim){
                count++;
            }else{
                if(count > maxcount){
                    result = sim;
                    maxcount = count;
                }
                cout<<sim<<" "<<count<<endl;
                sim=nums[i];
                count=1;
            }
        }
        if(count > maxcount){
            result = sim;
        }
        return result;
    }
};