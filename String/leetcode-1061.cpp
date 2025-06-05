#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    char dfsminchar(unordered_map<char, vector<char>> &adj, vector<int> &visited, char ch)
    {
        visited[ch-'a']=1;
        char mincha = ch;
        for(char &v: adj[ch])
        {
            if(visited[v-'a']!=1)
            {
                mincha = min(mincha, dfsminchar(adj, visited, v));      
            }
        }
        return mincha;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        unordered_map<char, vector<char>> adj;
        for(int i=0; i<n; i++)
        {
            char u= s1[i];
            char v= s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        for(int i=0; i<m; i++)
        {
            char ch = baseStr[i];
            vector<int> visited(26,0);
            char minchar =  dfsminchar(adj, visited, ch);

            result.push_back(minchar);
        }
        return result;
    }
};