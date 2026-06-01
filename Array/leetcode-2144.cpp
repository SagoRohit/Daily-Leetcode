#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int mincost=0;
        int count=1;
        sort(cost.begin(), cost.end());
        for(int i=n-1; i>=0; i--){
            if(count==3){
                count=1;
                continue;
            }else{
                mincost+=cost[i];
                count++;
            }
        }
        return mincost;
    }
};
int main(){
    Solution s;
    vector<int> cost={1,2,3};
    cout<<s.minimumCost(cost)<<endl;
    return 0;
}