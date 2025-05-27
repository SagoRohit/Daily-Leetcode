#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int &n: nums){
            pq.push(n);
        }
        int a = pq.top()-1;
        pq.pop();
        int b= pq.top()-1;
        return a*b;
    }
};