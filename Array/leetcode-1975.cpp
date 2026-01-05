#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result=0;
        int mini=INT_MAX;
        int negc=0;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                int val = matrix[i][j];
                mini = min(mini, abs(val));
                if(val<0){
                    negc++;
                    result+= (0-val);
                }else
                    result+= val;
                    
            }
        }
        if(negc%2==0)
            return result;
        cout<<result<<mini<<endl;
        return result-2LL* mini;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> vec = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout<<sol.maxMatrixSum(vec)<<endl;
    return 0;
}