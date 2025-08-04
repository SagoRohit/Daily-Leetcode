#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int n = numRows;
        for(int i=0; i<n; i++)
        {
            vector<int> v(i+1,1);
            for(int j=1; j<i; j++)
            {
                v[j]= result[i-1][j] + result [i-1][j-1];
            }
            result.push_back(v);
        }
        return result;
    }
};