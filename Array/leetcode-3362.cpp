#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int, vector<int>, greater<int>> used_query; //minheap
        priority_queue<int> available; //maxheap
        sort(queries.begin(), queries.end());
        int qpos = 0;
        int applied=0;
        for(int i=0; i<nums.size(); i++){
            while(qpos<queries.size() && queries[qpos][0]==i){
                available.push(queries[qpos][1]);
                qpos++;
            }
            nums[i] -= used_query.size();

            while(nums[i]>0 && !available.empty() && available.top()>=i){
                used_query.push(available.top());
                available.pop();
                nums[i]--;
                applied++;
            }
            if(nums[i]>0)
                return -1;
            while(!used_query.empty() && used_query.top()==i){
                used_query.pop();
            }
        }
        return queries.size()-applied;
    }
};