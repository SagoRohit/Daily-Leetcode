#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

//      Gives TLE 

// class Solution {
// public:
//     int bfs(int curr, unordered_map<int, vector<int>> &adj, int n, bool is1stree){
//         queue<pair<int, int>> pq;
//         pq.push({curr, 0+is1stree});
//         int count=0;
//         vector<bool> visited(n, false);
//         visited[curr]=true;
//         while(!pq.empty()){
//             int currnode = pq.front().first;
//             int dist = pq.front().second;
//             pq.pop();
//             if(dist & 1)
//                 count++;
//             for(auto nhbr: adj[currnode]){
//                 if(!visited[nhbr]){
//                     visited[nhbr]= true;
//                     pq.push({nhbr, dist+1});
//                 }
//             }
//         }
//         return count;
//     }
//     vector<int> findcount(vector<vector<int>> edge, bool is1stree){
//         unordered_map<int , vector<int>> adj;
//         int n = edge.size()+1;
//         for(auto ed: edge)
//         {
//             int u = ed[0];
//             int v = ed[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<int> result;
//         for(int i=0; i<n; i++)
//         {
//             result.push_back(bfs(i, adj, n, is1stree));
//         }
//         return result;
//     }
//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         int n = edges1.size()+1;
//         vector<int> result1= findcount(edges1, true);
//         vector<int> result2= findcount(edges2, false);

//         int mxcount= *max_element(begin(result2), end(result2));
//         for(int i=0; i<n; i++){
//             result1[i]+= mxcount;
//         }
//         return result1;
//     }
// };

class Solution {
public:
    unordered_map<int, vector<int>> makeadj(vector<vector<int>> edges){
        unordered_map<int, vector<int>> adj;
        for(auto edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(int curr, unordered_map<int, vector<int>> &adj, int parent, int &zcount, int &ocount, vector<int> &marked){
        if(marked[curr]==0){
            zcount++;
        }else{
            ocount++;
        }

        for(auto &nhbr: adj[curr]){
            if(nhbr!=parent)
            {
                marked[nhbr]= !marked[curr];
                dfs(nhbr, adj, curr, zcount, ocount, marked);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int N = edges1.size()+1;
        int M = edges2.size()+1;

        unordered_map<int, vector<int>> adjA = makeadj(edges1);
        unordered_map<int, vector<int>> adjB = makeadj(edges2);

        int zcountA = 0;
        int ocountA= 0;
        vector<int> markedA(N, -1);
        dfs(0, adjA, -1, zcountA, ocountA, markedA);

        int zcountB =0;
        int ocountB =0;
        vector<int> markedB(M, -1);
        dfs(0, adjB, -1, zcountB, ocountB, markedB);

        int mxcount = max(zcountB,ocountB);
        vector<int> result(N);

        for(int i=0; i<N; i++){
            int marking = markedA[i];
            if(marking==0)
            {
                result[i]= zcountA+ mxcount;
            }else{
                result[i]= ocountA+ mxcount;
            }
        }
        return result;
    }
};