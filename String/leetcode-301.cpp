#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int n;
    unordered_set<string> st;
    int maxlen;
    void solve (const string& s, int ind, string& curr, int count){
        if(count < 0) // invalid string, as count goes negative 
            return ;
        if(ind == n) { // base case
            if(count == 0) // valid 
            { 
                if(curr.length() > maxlen) {
                    maxlen = curr.length();
                    st.clear();
                }
                if(curr.length() == maxlen) {
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[ind] != '(' and s[ind] != ')') {
            curr.push_back(s[ind]);
            solve(s, ind+1, curr, count);
            curr.pop_back();
            return;
        }
        curr.push_back(s[ind]);
        solve(s, ind+1, curr, count + (s[ind]=='('?1:-1));
        curr.pop_back();
        solve(s, ind+1, curr, count);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        maxlen = 0;
        st.clear();
        string curr = "";
        solve(s, 0, curr, 0);
        return vector<string> (begin(st), end(st));
    }
};