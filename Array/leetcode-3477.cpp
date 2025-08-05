#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n= fruits.size();
        int m = baskets.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            int j;
            for(j=0; j<m; j++)
            {
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    break;
                }
            }
            if(j==m)
                count++;
        }
        return count;
    }
};