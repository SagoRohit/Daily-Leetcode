#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        // so we use grid balance approach to solve this problem
        // for ( we increment, for ) we decrement, finally if total is 0, then
        // the string is balanced. this is vps approach
        // now to handle * (wildcard), we treat this as ( -> for maximum val
        // and * -> ) for min val. now if we get the min val as 0 or less, then there 
        // must be a path that reach to 0 (balanced). then why we calculate max?
        // to check if anywhere is goes negative, then the string is invalid.
        // refer to the solution of leetcode for better visualization

        int l = 0, h = 0;
        for(char c: s) {
            // this is lower/min value that we are tracing
            l = ((c=='(')<<1) - 1; // if the char is (, then l increment by 1. 
            // if not, then decrement by 1. 
            // c==( check if it is (, is so, returns 1. so it becomes 1<<1 which my in
            // binary 10 or 2 in decimal. and finally 2-1 = 1; so increment by 1.
            // if not, then 0-1= -1, decrement by 1;
            h = ((c!=')')<<1)-1; // this tracks higher val, except for ), it always increment
            // by 1.
            if(h<0)
                return 0; // by any chance if higher goes negative, string is invalid.
            l = max(l,0); // we cap down l to 0
        }
        return l==0;
    }
};