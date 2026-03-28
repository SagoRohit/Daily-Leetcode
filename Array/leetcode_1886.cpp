#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // rotation => transpose + flip/reverse column wise
    vector<vector<int>> rotaionMat(vector<vector<int>> &mat){
        int n = mat.size();
        
        // transpose the matrix
        vector<vector<int>> transpose(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                transpose[i][j]= mat[j][i];
            }
        }

        // time to flip the matrix column
        vector<vector<int>> result(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result[i][j]= mat[j][n-i-1];
            }
        }
        return result;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
            return true;
        for(int rotaion=1; rotaion<=3; rotaion++){
            mat = rotaionMat(mat);
            if(mat==target)
                return true;
        }
        return false;
    }
};
int main(){

    return 0;
}