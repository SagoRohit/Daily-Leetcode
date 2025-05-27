#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int result=0;
        for(auto &num: grid){
            sort(num.begin(), num.end());
        }    
        int mx=-1;
        for(int i=0; i<grid[0].size(); i++){
            for(int j=0; j<grid.size(); j++){
                mx = max(mx, grid[j][i]);
            }
            result+= mx;
        } 
        return result;
    }
};