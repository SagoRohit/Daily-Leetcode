#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rowarr(mat.size());
        vector<int> colarr(mat[0].size());
        int result=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    rowarr[i]++;
                    colarr[j]++;
                }
            }
        }
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0)
                    continue;
                if(mat[i][j]==1 and rowarr[i]==1 and colarr[j]==1)
                    result++;
            }
        }
        return result;
    }
};