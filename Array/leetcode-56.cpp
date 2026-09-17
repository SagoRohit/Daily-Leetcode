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
            // cout<<"inside";
            auto temp = st.top();
            st.pop();
            if(temp.second >= intervals[i][0]){
                int large = (intervals[i][1] > temp.second)? intervals[i][1]:temp.second;
                // cout<<temp.first<< large<<endl;
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
};
int main(){
    Solution sol;
    // // 1,4],[0,2],[3,5
    // (0,2), (1,4), (3,5)
    // (0,4), (3,5)
    vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    vector<vector<int>> ans = sol.merge(intervals);
    for(auto n: ans){
        for(int ni: n){
            cout<<ni<<" ";
        }
        cout<<endl;
    }
    return 0;
}