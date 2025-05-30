#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    vector<int> dfsdistcount(unordered_map<int, vector<int>>& adj, int curr, int n) {
        vector<int> result(n, -1);
        queue<pair<int, int>> pq;
        vector<bool> visited(n, false);
        pq.push({curr, 0});
        visited[curr] = true;
        while (!pq.empty()) {
            int currnode = pq.front().first;
            int dist = pq.front().second;
            pq.pop();
            if (currnode < n)
                result[currnode] = dist;
            for (auto& nhbr : adj[currnode]) {
                if (!visited[nhbr]) {
                    visited[nhbr] = true;
                    pq.push({nhbr, dist + 1});
                }
            }
        }
        return result;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        vector<int> dist1(n, -1);
        dist1 = dfsdistcount(adj, node1, n);
        vector<int> dist2(n, -1);
        dist2 = dfsdistcount(adj, node2, n);

        vector<int> mxdist(n, 0);
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                mxdist[i] = max(dist1[i], dist2[i]);
            } else {
                mxdist[i] = INT_MAX;
            }
        }
        int mini = INT_MAX;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (mini > mxdist[i]) {
                mini = mxdist[i];
                ind = i;
            }
        }
        return ind;
    }
};