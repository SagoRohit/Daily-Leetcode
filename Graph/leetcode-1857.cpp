#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.length();
        unordered_map<int, vector<int>> adj;
        vector<int>indegree(N,0);
        
        //populating the adj
        for(auto &edge: edges){
            int u = edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<vector<int>> t(N, vector<int>(26,0));
        queue<int> que;
        //pushing the starting node, that has 0 indegree and populating cost matrix
        for(int i=0; i<N; i++){
            if(indegree[i]==0){
                que.push(i);
                t[i][colors[i]-'a']=1;
            }
        }
        int ans=0;
        int nodecount=0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            nodecount++;
            ans= max(ans, t[u][colors[u]-'a']);
            for(int &v: adj[u]){
                for(int i=0; i<26; i++){
                    //checking if the color of v is the same as i
                    t[v][i]= max(t[v][i], t[u][i]+ (colors[v]-'a'==i));
                }
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if(nodecount<N)
            return -1;
        return ans;
    }
};