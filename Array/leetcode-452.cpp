#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)
            return 1;
        sort(points.begin(), points.end());
        stack<pair<int,int>> st;

        if(points[0][1] >= points[1][0]) {
            st.push({max(points[0][0], points[1][0]), min(points[0][1], points[1][1])});
        }else {
            st.push({points[0][0], points[0][1]});
            st.push({points[1][0], points[1][1]});
        }


        for(int i=2; i<n; i++){
            auto temp = st.top();
            st.pop();
            if(temp.second >= points[i][0])
            {
                st.push({max(temp.first, points[i][0]), min(temp.second, points[i][1])});
            } else {
                st.push ({temp.first, temp.second});
                st.push({points[i][0], points[i][1]});
            }
        }
        return st.size();
    }
};

// (1,6), (2,8), (7,12), (10,16)
// (1,8)
// common point : max(start), min(end)
// so stack stores the common point. if no common point, then store the real position.
int main(){
    Solution sol;
    vector<vector<int>> vec = {{1,2},{2,3},{3,4},{4,5}};
    cout<<sol.findMinArrowShots(vec)<<endl;
    return 0;
}