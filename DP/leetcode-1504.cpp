#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int submatcount(vector<int> &arr)
    {
        int count=0;
        int subseq=0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]==1)
                subseq++;
            else
                subseq=0;
            count+= subseq;
        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result=0;
        for(int start=0; start<m; start++)
        {
            vector<int> arr(n, 1);
            for(int end=start; end<m; end++)
            {
                for(int col=0; col<n; col++)
                {
                    arr[col]= arr[col] & mat[end][col];
                }
                result+= submatcount(arr);
            }
        }
        return result;
    }
};