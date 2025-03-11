#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int mini, maxi= 0 ;
        for(auto n: grid){
            mini = INT_MAX;
            for(int m: n){
                if(m<mini)
                    mini = m;
            }
            if(mini>maxi)
                maxi = mini;
        }
        return maxi;
    }
};