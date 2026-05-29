#include<iostream>
#include<vector>
using namespace std;
void dfsrec(vector<vector<int>> &adj, vector<int> &res, vector<bool> visited, int s){
    visited[s] = true;
    res.push_back(s);
    for(int i: adj[s]){
        if(visited[i]==false){
            dfsrec(adj, res, visited, i);
        }
    }
}
vector<int> dfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;
    dfsrec(adj, res, visited, 0);
    return res;
}