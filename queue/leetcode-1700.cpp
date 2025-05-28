#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int curr=0;
        queue<int> pq;
        int count=0;
        for(int &i: students){
            pq.push(i);
        }
        while(!pq.empty() && count<pq.size()){
            if(sandwiches[curr]!=pq.front()){
                pq.push(pq.front());
                pq.pop();
                count++;
            }
            else{
                curr++;
                pq.pop();
                count=0;
            }
        }
        return pq.size();
    }
};