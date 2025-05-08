#include <iostream>
#include <vector>
#include<queue>
using namespace std;
class Solution
{
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0,0}});

        while(!pq.empty()){
            int time = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();
            if(i==m-1 && j==n-1)
                return time;
            for(auto &dir: directions){
                int i_ = dir[0]+ i;
                int j_ = dir[1]+j;

                if(i_>=0 && i_<m && j_>=0 && j_<n){
                    int step = (i_ + j_) % 2==0? 2: 1;
                    int wait = max(moveTime[i_][j_] -  time, 0);

                    int finaltime = time+ wait +step;

                    if(result[i_][j_] > finaltime){
                        result[i_][j_] = finaltime;
                        pq.push({finaltime, {i_, j_}});
                    }
                }


            }
        }
        return -1;
    }
};