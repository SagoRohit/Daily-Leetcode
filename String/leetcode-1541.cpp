#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int im = 0;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i+1]==')'){
                if(!st.empty()){
                    st.pop();
                }else{
                    im++;
                }
                i++;
            }else{
                if(!st.empty()){
                    im++;
                    st.pop();
                }else{
                    im+=2;
                }
            }
        }
        im+= st.size()*2;
        return im;
    }
};
int main() {
    Solution sol;
    string s = "())";
    cout<<sol.minInsertions(s)<<endl;
    return 0;
}