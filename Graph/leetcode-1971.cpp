#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> visited(n, false);
       return dfs(visited, source, destination, graph);
    }
    bool dfs(vector<bool>&visited, int curr, int des, vector<vector<int>>&graph){
        if(curr==des)
            return true;
        visited[curr]= true;
        for(int neighbour: graph[curr]){
            if(!visited[neighbour]){
                if(dfs(visited, neighbour, des, graph))
                    return true;
            }
        }
        return false;
    }
};