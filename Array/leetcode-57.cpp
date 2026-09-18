#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        stack<pair<int, int>> st;
        if(intervals[0][1] >= intervals[1][0]){
            int large = (intervals[0][1] > intervals[1][1])? intervals[0][1]: intervals[1][1];
            st.push({intervals[0][0], large});
        }else {
            st.push({intervals[0][0], intervals[0][1]});
            st.push({intervals[1][0], intervals[1][1]});

        }
        for(int i=2; i<intervals.size(); i++){
            auto temp = st.top();
            st.pop();
            if(temp.second >= intervals[i][0]){
                int large = (intervals[i][1] > temp.second)? intervals[i][1]:temp.second;
                st.push({temp.first, large});
            }else{
                st.push({temp.first, temp.second});
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            result.push_back({temp.first, temp.second});
        }
        reverse(result.begin(), result.end());
        return result;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back({newInterval[0], newInterval[1]});
        return merge(intervals);
    }
};