#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long ans=0;
            int minpos=-1;
            int maxpos=-1;
            int out=-1;

            for(int i=0; i<nums.size(); i++){
                if(nums[i]<minK||nums[i]>maxK)
                    out = i;
                if(nums[i]==minK)
                    minpos=i;
                if(nums[i]==maxK)
                    maxpos=i;
                long long smaller = min(minpos, maxpos);
                long long temp = smaller - out;
                 ans+= (temp<0)? 0: temp;
            }
            return ans;
        }
};
int main(){

    return 0;
}
