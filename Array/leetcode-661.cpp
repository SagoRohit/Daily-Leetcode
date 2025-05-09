#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1},{0,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        vector<vector<int>> result(m, vector<int>(n,0));
        

        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                int count=0;
                int sum=0;
                for(auto &dir: dirs){
                    int i_ = dir[0]+ i;
                    int j_ = dir[1] + j;
                    if(i_>=0 && i_<m && j_>=0 && j_<n){
                        count++;
                        sum+= img[i_][j_];
                    }
                }
                result[i][j]=floor(sum/count);
            }
        }
        return result;
    }
};