#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result (m-k+1, vector<int>(n-k+1));

        for(int i = 0; i <= m-k; i++){
            for(int j =0; j<= n-k; j++){
                set<int> val;
                for(int r = i; r<= i+k-1; r++){
                    for(int c=j; c<= j+k-1; c++){
                        val.insert(grid[r][c]);
                    }
                }
                if(val.size()==1){
                    result[i][j]=0;
                    continue;
                }
                int minabsdiff= INT_MAX;
                auto prev = val.begin();
                auto curr = next(prev);
                while(curr != val.end()){
                    minabsdiff = min(minabsdiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                result[i][j]= minabsdiff;
            }
        }
        return result;
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
    vector<vector<int>> grid= {{3,-1}};
    vector<vector<int>> result = sol.minAbsDiff(grid, 1);
    sol.print(result);
    return 0;
}