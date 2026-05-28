#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// using sort function O(n log n)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int j=0;
//         for(int i=m; i<m+n; i++){
//             nums1[i]=nums2[j];
//             j++;
//         }
//         sort(nums1.begin(), nums1.end());
//     }
// };

class Solution {
public: 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        // here we are moving the larger elements in the back of nums1. and the comparison is started from
        // the back of both non-void part.
        while(j>=0){
            if(i>=0 and nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};
