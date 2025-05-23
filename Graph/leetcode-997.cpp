#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>  indegree(n+1, 0);
        vector<int> outdegree(n+1, 0);
        for(auto t: trust){
            int ai = t[0];
            int bi = t[1];
            indegree[bi]++;
            outdegree[ai]++;
        }
        for(int i=1; i<=n; i++){
            if(indegree[i]==n-1 && outdegree[i]==0)
                return i;
        }
        return -1;
    }
};