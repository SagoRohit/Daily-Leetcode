#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[i]= nums[i]+nums[i-1];
        }
        this->prefixsum= nums;
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return prefixsum[right];
        return prefixsum[right]-prefixsum[left-1];
    }
};

int main(){
    vector<int> arr = {-2, 0, 3, -5, 2, -1};

    NumArray obj(arr);
    cout<<obj.sumRange(2,5)<<endl;
    return 0;
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */