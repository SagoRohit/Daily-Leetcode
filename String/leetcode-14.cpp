#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string matching(string s, string l){
        string match="";
        int i=0;
        while((i<s.length() && i<l.length()) && s[i]==l[i]){
            match += s[i];
            i++;
        }
        return match;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string com=strs[0];
        for(auto s: strs){
            com = matching(com, s);
        }
        return com;
    }
};
int main(){
    Solution sol;
    vector<string> s={"flower", "flow", "flight"};
    cout<<sol.longestCommonPrefix(s);
    return 0;
}