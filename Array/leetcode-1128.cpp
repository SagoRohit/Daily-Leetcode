#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> mp;
            int count=0;
            for(auto &d: dominoes){
                if(d[0]>d[1])
                    swap(d[0],d[1]);
                count+= mp[make_pair(d[0],d[1])]++;
            }
            return count;
        }
};
        
         //O(n2) solution (TLE)
            // int n = dominoes.size();
            // int count=0;
            // for(int i=0; i<n; i++){
            //     for(int j=i+1; j<n; j++){
            //         int a = dominoes[i][0], b= dominoes[i][1];
            //         int c = dominoes[j][0], d= dominoes[j][1];
            //         if(a==c && b==d || c==d && c==b)
            //             count++;
            //     }
            // }
            // return count;      