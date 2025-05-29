#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> map;
       stack<int> st;
       for(int &n: nums2)
       {
            while(!st.empty() && st.top()<n)
            {
                map[st.top()]= n;
                st.pop();
            }
            st.push(n);
       }
       while(!st.empty())
       {
            map[st.top()]=-1;
            st.pop();
       }
       vector<int> result;
       for(int &num: nums1){
            result.push_back(map[num]);
       }
       return result;
    }
};