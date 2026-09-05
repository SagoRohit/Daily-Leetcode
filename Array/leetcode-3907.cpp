#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxelements(n,0);
        vector<int> minelements(n,0);
        // first pass
        int maxval = -1;
        for(int i=0; i<n; i++){
            if(nums[i]>maxval)
                maxval = nums[i];
            maxelements[i]= maxval;
        }
        // 2nd pass
        int minval = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<minval)
                minval = nums[i];
            minelements[i]= minval;
        }
        for(int i=0; i<n; i++){
            int score = maxelements[i]-minelements[i];
            if(score <= k)
                return i;
        }
        return -1;
    }
};