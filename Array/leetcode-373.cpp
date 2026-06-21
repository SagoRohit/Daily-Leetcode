#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p, vector<p>> pq;
        for(int i=0; i<nums1.size(); i++) {
            for(int j = 0; j<nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else{
                    break;
                }
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
        }
        return result;
    }
};


class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        set<pair<int, int>> visited;
        vector<vector<int>> result;

        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0,0}});
        visited.insert({0,0});
        
        while(k-- and !pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
            // now we explore (i+1, j)
            if(i+1 < m and visited.find({i+1,j})==visited.end()){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1,j});
            }
            // now we explore (i, j+1)
            if(j+1 < n and visited.find({i,j+1})==visited.end()){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};