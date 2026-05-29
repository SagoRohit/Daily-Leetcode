#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reversearr(vector<int> &num, int start, int end){
        while(start<end){
            swap(num[start], num[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        reversearr(nums, 0, n-1);
        reversearr(nums, 0, k-1);
        reversearr(nums, k, n-1);
    }
};