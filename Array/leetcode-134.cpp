#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int start=0; start<n; start++){
            long long tank=0;
            int i = start;
            bool route = true;
            int count = 0;
            while(count!=n){
                tank+= gas[i%n];
                if(tank < cost[i%n]){
                    route = false;
                    break;
                }
                tank -= cost[i%n];
                i++;
                count++;
            }
            if(route){
                return start;
            }
        }
        return -1;
    }
};