#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start;
        for(start = 0; start < n; start++){
            int end=-1;
            int total_gas=0;
            int i= start;
            int station_count=0;
            while(station_count<n){
                total_gas+= gas[i%n];
                if(cost[i%n] < total_gas){
                    end = i;
                }else{
                    break;  
                }
                i++;
                station_count++;
            }
            if(start==end){
                return start;
            }
        }
        return -1;
    }
};  
int main(){
    Solution sol;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<sol.canCompleteCircuit(gas, cost)<<endl;
    return 0;
}