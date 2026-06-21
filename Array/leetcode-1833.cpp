#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(int n: costs) {
            if(coins >= n){
                count++;
                coins -= n;
            }
            else
                break;
        }
        return count;
    }
};