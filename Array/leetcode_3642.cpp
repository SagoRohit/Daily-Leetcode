#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=y; j<y+k; j++){
            vector<int> submatrix;
            for(int i=x; i<x+k; i++){
                submatrix.push_back(grid[i][j]);
            }
            reverse(begin(submatrix),end(submatrix));
            for(int i=x, r=0; i<x+k; i++, r++){
                grid[i][j]= submatrix[r];
            }
        }
        return grid;
    }
    void print(vector<vector<int>> &result){
        for(int i=0; i<result.size(); i++){
            for(int j=0; j<result[0].size(); j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Solution sol;
    vector<vector<int>> grid={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> result= sol.reverseSubmatrix(grid, 1,0,3);
    sol.print(result);
    return 0;
}