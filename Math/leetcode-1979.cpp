#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto it = min_element(nums.begin(), nums.end());
        int smallest = *it;
        it = max_element(nums.begin(), nums.end());
        int largest = *it;
        for(int i=smallest; i>=1; i--){
            if(largest%i==0 and smallest%i==0)
                return i;
        }
        return 1;
    }
};
int main(){
    Solution sol;
    vector<int> num = {7,5,6,8,3};
    cout<<sol.findGCD(num);
    return 0;
}