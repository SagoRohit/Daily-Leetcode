#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for(int i=0; i<prices.size(); i++){
            if(buy < prices[i]){
                profit += prices[i] - buy;  // price beshi, sell korbo
            }
            buy = prices[i]; // everyday is buy day
        }
        return profit;
    }
};