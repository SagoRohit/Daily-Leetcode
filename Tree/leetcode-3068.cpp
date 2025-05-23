#include<iostream>
#include<vector>
using namespace std;

//here we do no need to check the edges, because we can change any two nodes, as they are obviously
//through a path form the node1 -> node2
//so if the count of changes is even, we simply return the value of sum otherwise 
//we check the loss that we may face because of changing or not changing the node value.
//for further explanantion check the video of codestorywithmike 

class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum =0;
        int count=0;
        int minloss = INT_MAX;
        for(int num: nums){
            if((num^k)>num){
                sum+= (num^k);
                count++;
            }else{
                sum+= num;
            }
            minloss = min(minloss, abs(num- (num^k)));
        }
        if(count%2==0)
            return sum;
        else
            return (sum-minloss);
    }
};