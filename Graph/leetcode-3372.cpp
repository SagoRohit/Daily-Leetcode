#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int bfs(int curr, unordered_map<int, vector<int>>& adj, int n, int d){
        queue<pair<int, int>> pq;
        pq.push({curr,0});
        int count=0;
        vector<bool>visited(n, false);
        visited[curr]= true;
        while(!pq.empty()){
            int currnode = pq.front().first;
            int dist = pq.front().second;
            pq.pop();
            if(dist>d)
            {
                continue;
            }
            count++;
            for(auto nhbr: adj[currnode])
            {   
                if(!visited[nhbr])
                {
                    visited[nhbr]= true;
                    pq.push({nhbr, dist+1});
                }
            }
        }
        return count;
    }
    vector<int> findcount(vector<vector<int>> edge,  int d){
        int N = edge.size()+1;
        unordered_map<int, vector<int>> adj;
        for(auto &n: edge){
            int u = n[0];
            int v = n[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(N);
        for(int i=0; i<N; i++){
            result[i]= bfs(i, adj, N, d);
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int N= edges1.size()+1;
        vector<int> result1 = findcount(edges1, k);
        vector<int> result2 = findcount(edges2, k-1);
        
        int maxcount = *max_element(begin(result2), end(result2));
        for(int i=0; i<N; i++){
            result1[i]+= maxcount;
        }
        return result1;
    }
};