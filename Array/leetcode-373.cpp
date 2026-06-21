#include<iostream>
#include<vector>
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