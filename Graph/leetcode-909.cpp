#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int  n = board.size();

        auto cordinate = [&](int s){
            int r = n-1 - (s-1)/n;
            int c = (s-1)%n;
            if((n-r)%2==0)
                c= n-1-c;
            return make_pair(r, c);
        };

        vector<bool> visited(n*n+1, false);
        queue<pair<int, int>> pq;
        pq.push({1,0});
        while(!pq.empty())
        {
            auto [curr, move]= pq.front();
            pq.pop();
            if(curr==n*n)
                return move;
            for(int i=1; i<=6 && curr+i<=n*n; i++)
            {
                int next = curr+i;
                auto [r,c]= cordinate(next);
                if(board[r][c]!=-1){
                    next = board[r][c];
                }
                if(!visited[next]){
                    visited[next]= true;
                    pq.push({next, move+1});
                }
            }
        }
        return -1;
    }
};