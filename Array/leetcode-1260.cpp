#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = i * n + j; // faltten index of the grid elemnts
                int newindex = (index + k) % total;
                int newindex_row = newindex / n;
                int newindex_col = newindex % n;

                result[newindex_row][newindex_col] = grid[i][j];
            }
        }
        return result;
    }
};


