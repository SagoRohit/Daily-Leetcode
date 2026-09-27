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
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr;
        for(char c: s) {
            if(c == '('){
                st.push(curr);
                curr.erase();
            } else if(c == ')'){
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else
                curr += c;
        }
        return curr;
    }
};

int main() {
    Solution sol;
    string st = "(ed(et(oc))el)";
    cout<<sol.reverseParentheses(st)<<endl;
    return 0;
}