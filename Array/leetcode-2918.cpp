#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    using ll= long long;
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int c1=0, c2=0;
        ll sum1=0, sum2=0;
        for(int &n: nums1){
            if(n==0)
                c1++;
            sum1+= n;
        }
        for(int &n: nums2){
            if(n==0)
                c2++;
            sum2+= n;
        }
        ll min1 = sum1+c1;
        ll min2 = sum2+c2;
        ll target = max(min1, min2);
        if(target> sum1 && c1==0)
            return -1;
        else if(target> sum2 && c2==0)
            return -1;
        return target;
    }
};