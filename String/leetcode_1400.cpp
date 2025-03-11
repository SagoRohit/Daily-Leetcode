/*1400. Construct K Palindrome Strings
Medium
Topics
Companies
Hint
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105
*/

#include<iostream>
#include<unordered_map>
#include<string.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        int cnt =0;
        if(k>s.length())
            return false;
        unordered_map<char, int> set;
        for(char c: s){
            set[c]++;
        }
        for(auto count: set){
            if(count.second%2!=0)
                cnt++;
        }
        if(cnt>k)
            return false;
        return true;
    }
};