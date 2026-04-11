#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>&arr, int target, int left, int right){
        if(left>right)
            return -1;
        int mid = left + (right-left)/2;
        if(arr[mid]==target)
            return mid;
        // if the left subarray is sorted: first element will be less than last element
        if(arr[left]<=arr[mid]){
            // if the target is in this subarray
            if(arr[left]<=target and target<=arr[mid]){
                return solve(arr, target, left, mid-1);
            }else{
                return solve(arr, target, mid+1, right);
            }
        }else{ // so the right subarray is sorted
            if(arr[mid]<=target and target<=arr[right]){
                return solve(arr, target, mid+1, right);
            }else{
                return solve(arr, target, left, mid-1);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size()-1);
    }
};