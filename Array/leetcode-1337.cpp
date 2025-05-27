#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //min-heap
        for(int i=0; i<mat.size(); i++){
            int count=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j])
                    count++;
            }
            pq.push({count, i});
        }
        vector<int> result;
        while(k){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};