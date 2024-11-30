/* This is Leetcode No-3 medium marked problem.

Problem statement: 
Given a string s, find the length of the longest 
substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/


#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int len = s.length();
        int maxlen = 0;
        unordered_set<char> st;

        for (int right = 0; right < len; right++)
        {
            while (st.find(s[right]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
int main()
{
    Solution sol;
    string s = "pwwkew";
    cout << sol.lengthOfLongestSubstring(s);

    return 0;
}