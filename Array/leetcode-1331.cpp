#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank = arr;
        sort(rank.begin(), rank.end());
        unordered_map<int, int> map;
        int currRank = 1;
        for(int n: rank){
            if(!map.count(n)){
                map[n]= currRank++;
            }
        }
        for(int &n: arr){
            n = map[n];
        }
        return arr;
    }
};
