#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(c=='(' or c=='{' or c=='['){
                st.push(c);
                continue;
            }
            if(st.size()==0)
                return false;
            char top = st.top();
            if(c==')' and top!='(')
                return false;
            else if(c=='}' and top!='{')
                return false;
            else if(c==']' and top!='[')
                return false;
            st.pop();
        }
        return st.size()==0;
    }
};