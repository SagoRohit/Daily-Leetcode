/*1614. Maximum Nesting Depth of the Parentheses
Easy
Topics
Companies
Hint
Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"

Output: 3

Explanation:

Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"

Output: 3

Explanation:

Digit 3 is inside of 3 nested parentheses in the string.

Example 3:

Input: s = "()(())((()()))"

Output: 3

 

Constraints:

1 <= s.length <= 100
s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
It is guaranteed that parentheses expression s is a VPS.*/
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
    stack<char> st;
    int cnt = 0;
    int maxCnt = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
            cnt++;
            maxCnt = max(maxCnt, cnt);
        } else if (c == ')') {
            if (!st.empty()) {
                st.pop();
                cnt--;
            } else {
                return -1; 
            }
        }
    }

    if (!st.empty()) {
        return -1; 
    }
    return maxCnt;
    }
};