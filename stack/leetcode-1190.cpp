#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        int i = 0;
        string ans = "";
        stack<char> st;
        while(i<n) {
            char c = s[i];
            if(c!= ')') {
                st.push(c);
                i++;
            }else {
                string temp = "";
                while(st.top()!='('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                for(char ch: temp) {
                    st.push(ch);
                }
                i++;
            }
        }
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string st = "(ed(et(oc))el)";
    cout<<sol.reverseParentheses(st)<<endl;
    return 0;
}