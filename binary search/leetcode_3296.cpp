#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    typedef long long ll;
    bool check(ll mid, vector<int> &workerTimes, int mH){
        ll h = 0;
        for(int time : workerTimes){
            h += ll(sqrt(2.0 * mid/time + 0.25) - 0.5);
            if(h>= mH)
                return true;
        }
        return h>=mH;
    }
    long long minNumberOfSeconds(int mH, vector<int>& workerTimes) {
        int Tmax = *max_element(begin(workerTimes), end(workerTimes));
        ll result =0;
        ll l=1;
        ll r = ll(Tmax) * mH * (mH+1)/2;

        while(l<=r){
            ll mid = l+ (r-l)/2;
            if(check(mid, workerTimes, mH)){
                result = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return result;
    }
};